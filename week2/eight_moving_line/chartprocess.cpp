#include "chartprocess.h"
ChartProcess::ChartProcess(QObject *parent,const QString filePath,QChartView *View):QObject(parent){
    Path=filePath;
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    widget=new QWidget;
    chartView=View;
    chartView->setChart(chart);
    series = new QSplineSeries(chart);
    thread = new QThread();
    dataReader = new DataReader(nullptr,"data.txt");
    connect(dataReader, &DataReader::sendSeries, this, &ChartProcess::slotUpdate);
    dataReader->moveToThread(thread);
    thread->start();
    dataReader->StartInit();
    //现在的问题是……有两条路。一条是按照two_threads的思路走。一条是再建一个画图的线程（也不是不行）
}
ChartProcess::~ChartProcess(){
    thread->quit();
}
void ChartProcess::beginThread(){
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(false);
    axisX->setRange(0, POINTSNUMBER);
    axisX->setTickCount(POINTSNUMBER/10);
    axisX->setLabelFormat("%.0f");
    axisY->setRange(-1, 4);
    axisY->setTickCount(1.0);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

}
void ChartProcess::slotUpdate(QVector<qreal> data)
{
    qDebug()<<"updata";
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
