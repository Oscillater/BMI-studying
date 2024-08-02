#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    resize(1000,600);
    button = new QPushButton("点我",this);
    button->setGeometry(50,50,100,30);
    connect(button,&QPushButton::clicked,this,&MainWindow::onButtonClicked);
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(false);
    axisX->setRange(0, POINTSNUMBER);
    axisX->setTickCount(POINTSNUMBER/10);
    axisX->setLabelFormat("%.0f");
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);
    chartView = new QChartView();
    series = new QSplineSeries(chart);
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chart->setTitle("TWO THREAD");
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
        series->append(x,y);
        if (Position>POINTSNUMBER){
            axisX->setRange(Position-POINTSNUMBER,Position);
            axisX->setLabelFormat("%.0f");
            axisX->setTickCount(POINTSNUMBER/10);
        }
    }

}
void MainWindow::onButtonClicked()
{
    setCentralWidget(chartView);
    work = new Work(nullptr,"data.txt");
    thread = new QThread();
    connect(work, &Work::sendSeries, this, &MainWindow::slotUpdate);
    work->moveToThread(thread);
    thread->start();
    work->StartInit();
}
