#include "chartprocess.h"
ChartProcess::ChartProcess(QObject *parent,const QString filePath,const QString newname):QObject(parent){
    Path=filePath;
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    widget=new QWidget;
    chartView=new QChartView();
    chartView->setChart(chart);
    chartView->setFixedSize(1000,300);
    series = new QSplineSeries(chart);
    thread = new QThread();
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(false);
    chart->setTitle(newname);
    axisX->setRange(0, POINTSNUMBER);
    axisX->setTickCount(POINTSNUMBER/10);
    axisX->setLabelFormat("%.0f");
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    dataReader = new DataReader(nullptr,Path);
    connect(dataReader, &DataReader::sendSeries, this, &ChartProcess::slotUpdate);
    dataReader->moveToThread(thread);

}
ChartProcess::~ChartProcess(){
    thread->quit();
}
void ChartProcess::startThread(){
    thread->start();
    dataReader->StartInit();
}
void ChartProcess::slotUpdate(QVector<qreal> data)
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
