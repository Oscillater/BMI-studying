#ifndef DATAREADER_H
#define DATAREADER_H
#include <QObject>
#include <QTimer>
#include <QList>
#include <QPointF>
#include <Qdebug>
#include <QString>
#include <QFile>
#include <QRegularExpression>
#define STOPVALUE -1
class DataReader : public QObject
{
    Q_OBJECT
public:
    explicit DataReader(QObject *parent = nullptr,const QString &filePath="data.txt");
    ~DataReader();
    qreal getValueX();
    qreal getValueY();
signals:
    void sendSeries(const QVector<qreal> &data);
    void StartInit();

public slots:
    void slotStartInit();
    void processData();

private:

    QVector<qreal> data;
    int maxSize=10;
    QFile file;
    QTimer *timer;
    int LinePosition=0;
};
#endif // DATAREADER_H
