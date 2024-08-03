#include "datareader.h"
#include <QDebug>
#include <QThread>

DataReader::DataReader(QObject *parent,const QString &filePath) : QObject(parent),file(filePath)
{
    file.open(QIODevice::ReadOnly);
    qRegisterMetaType<QVector<qreal> >("QVector<qreal>");
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    line=in.readLine();
    numberStrs1 = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    line = in.readLine();
    numberStrs2 = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    connect(this, &DataReader::StartInit, this, &DataReader::slotStartInit);
}
DataReader::~DataReader(){
    file.close();
}
void DataReader::slotStartInit()
{
    timer=new QTimer();
    connect(timer, &QTimer::timeout, this, &DataReader::processData);
    timer->start(33);
}

qreal DataReader::getValueX(){
    qreal data;
    if (numberStrs1.size()<=LinePosition){
        return -1;
    }
    bool ok;
    data=numberStrs1.at(LinePosition).toDouble(&ok);
    LinePosition++;
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
qreal DataReader::getValueY(){
    qreal data;
    bool ok;
    if (numberStrs2.size()<=LinePosition){
        return -1;
    }
    data=numberStrs2.at(LinePosition).toDouble(&ok);
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
void DataReader::processData()
{
    data.clear();
    qreal x,y;
    x=getValueX();
    y=getValueY();
    if(x==STOPVALUE||y==STOPVALUE){
        timer->stop();
    }
    data.append(x);
    data.append(y);
    data.append(LinePosition);
    emit sendSeries(data);
}
