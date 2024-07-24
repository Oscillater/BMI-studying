#include "datareader.h"
DataReader::DataReader(const QString &filePath):file(filePath){
    file.open(QIODevice::ReadOnly);
}
DataReader::~DataReader(){
    file.close();
}
QVector<qreal> DataReader::readLine(bool lineIndex){
    QVector<qreal> data;
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    if (!lineIndex){
        line=in.readLine();
        firstLinePosition=POINTSNUMBER;
    }
    else{
        in.readLine();
        line = in.readLine();
        secondLinePosition=POINTSNUMBER;
    }
    QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    for (int i = 0; i < qMin(POINTSNUMBER, numberStrs.size()); ++i) {
        bool ok;
        qreal number = numberStrs.at(i).toDouble(&ok);
        if (ok) {
            data.append(number);
        } else {
            qDebug() << "Invalid number format:" << numberStrs.at(i);
        }
    }
    return data;
}

qreal DataReader::getValue(bool lineIndex){
    qreal data;
    QTextStream in(&file);
    if(!file.isOpen()){
        qDebug()<<"The file is not open.";
    }
    file.seek(0);
    QString line;
    bool ok;
    qDebug()<<firstLinePosition;
    if (!lineIndex){
        line=in.readLine();
        QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        data=numberStrs.at(firstLinePosition).toDouble(&ok);
        firstLinePosition++;
    }
    else{
        in.readLine();
        line = in.readLine();
        QStringList numberStrs = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        data=numberStrs.at(secondLinePosition).toDouble(&ok);
        secondLinePosition++;
    }
    if (ok) {
        return data;
    } else {
        qDebug() << "Error";
    }
}
