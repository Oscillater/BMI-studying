// mainwindow.cpp
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent,const QString &filePath)
    : QMainWindow(parent),reader(filePath)
{
    resize(1000, 600);
    button = new QPushButton("点我~", this);
    button->setGeometry(50, 50, 100, 30);
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    axisX->setRange(0, POINTSNUMBER);
    axisX->setTickCount(POINTSNUMBER/10);
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);
    axisX->setLabelFormat("%.0f");
    chart->setTheme(QChart::ChartThemeLight);
    series = new QSplineSeries();
    chartView = new QChartView(chart);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeoutHandler);
    timer.setInterval(33);
}
MainWindow::~MainWindow(){}
void MainWindow::onButtonClicked()
{
    QString filePath = "data.txt";
    DataReader reader(filePath);
    drawLineChart();
    timer.start();
}

void MainWindow::drawLineChart()
{
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    axisX->setLabelFormat("%.0f");
    axisX->setTickCount(POINTSNUMBER/10);
    chart->setTitle("MOVING LINE");
    chart->legend()->setVisible(false);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}
void MainWindow::timeoutHandler(){
    qreal xData,yData;
    xData=reader.getValueX();
    yData=reader.getValueY();
    if (xData==-1 || yData==-1){
        timer.stop();
    }
    else{
        series->append(xData, yData);
        int index=reader.getPosition();
        if( index > POINTSNUMBER)
            axisX->setRange(index-POINTSNUMBER,index);
            axisX->setLabelFormat("%.0f");
            axisX->setTickCount(POINTSNUMBER/10);
    }
}
