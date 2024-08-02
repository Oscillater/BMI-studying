#include "work.h"
#include <QDebug>
#include <QThread>

Work::Work(QObject *parent,const QString &filePath) : QObject(parent),file(filePath)
{
    file.open(QIODevice::ReadOnly);
    qRegisterMetaType<QVector<qreal> >("QVector<qreal>");
    connect(this, &Work::StartInit, this, &Work::slotStartInit);
}
Work::~Work(){
    file.close();
}
void Work::slotStartInit()
{
    timer=new QTimer();
    timer->start(33);
    connect(timer, &QTimer::timeout, this, &Work::processData);
}

qreal Work::getValueX(){
    qreal data;
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    bool ok;
    line=in.readLine();
    QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (numberStrs.size()<=LinePosition){
        return -1;
    }
    data=numberStrs.at(LinePosition).toDouble(&ok);
    LinePosition++;
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
qreal Work::getValueY(){
    qreal data;
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    bool ok;
    in.readLine();
    line = in.readLine();
    QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (numberStrs.size()<=LinePosition){
        return -1;
    }
    data=numberStrs.at(LinePosition).toDouble(&ok);
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
        return -1;
    }
}
void Work::processData()
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
