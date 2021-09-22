#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videocapture.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV_videoCapture = new VideoCapture(this);
    connect(mOpenCV_videoCapture, &VideoCapture::newPixmapCaptured, this, [&]()
    {
        ui->openCVFrame->setPixmap(mOpenCV_videoCapture->pixmap().scaled(500, 500));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    mOpenCV_videoCapture->terminate();
}


void MainWindow::on_btOpencv_clicked()
{
    qDebug() << "Yes";
    mOpenCV_videoCapture->start(QThread::HighPriority);
}

