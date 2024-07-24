#ifndef DATAREADER_H
#define DATAREADER_H
#define POINTSNUMBER 200
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QRegularExpression>
class DataReader{
public:
    DataReader(const QString &filePath);
    ~DataReader();
    QVector<qreal> readLine(bool lineIndex);
    qreal getValue(bool lineIndex);
private:
    QFile file;
    int firstLinePosition=0;
    int secondLinePosition=0;
};

#endif // DATAREADER_H
