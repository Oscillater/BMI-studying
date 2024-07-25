#include "datareader.h"
DataReader::DataReader(const QString &filePath):file(filePath){
    file.open(QIODevice::ReadOnly);
}
DataReader::~DataReader(){
    file.close();
}


qreal DataReader::getValueX(){
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
qreal DataReader::getValueY(){
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
int DataReader::getPosition(){
    return LinePosition;
}
