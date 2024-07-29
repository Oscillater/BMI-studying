#ifndef WORK_H
#define WORK_H
#include <QObject>
#include <QTimer>
#include <QList>
#include <QPointF>
#include <Qdebug>
#include <QString>
#include <QFile>
#include <QRegularExpression>
#define STOPVALUE -1
class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr,const QString &filePath="data.txt");
    ~Work();
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
#endif // WORK_H
