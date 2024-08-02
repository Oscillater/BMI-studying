#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Plot->addGraph();
    ui->Plot->xAxis->setRange(0, POINTSNUMBER);
    ui->Plot->yAxis->setRange(-1,4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdate(QVector<qreal> data)
{
    qreal x,y;
    int Position;
    x=data[0];
    y=data[1];
    Position=data[2];
    if(x==STOPVALUE || y==STOPVALUE){
        thread->quit();
    }
    else{
        ui->Plot->graph(0)->addData(x,y);
        ui->Plot->replot();
        if (Position>POINTSNUMBER){
            ui->Plot->xAxis->setRange(Position-POINTSNUMBER,Position);
        }
    }

}

void MainWindow::on_pushButton_clicked()
{
    work = new Work(nullptr,"data.txt");
    thread = new QThread();
    connect(work, &Work::sendSeries, this, &MainWindow::slotUpdate);
    work->moveToThread(thread);
    thread->start();
    work->StartInit();
}

