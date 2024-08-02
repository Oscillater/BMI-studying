#ifndef CHARTPROCESS_H
#define CHARTPROCESS_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVector>
#include <QPointF>
#include <QFile>
#include <QTextStream>
#include <QGraphicsLineItem>
#include <QRegularExpression>
#include<QString>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QTimer>
#include <QThread>
#include <QVBoxLayout>
#include "datareader.h"
#define POINTSNUMBER 200
#define STOPVALUE -1
class ChartProcess:public QObject{
    Q_OBJECT
public:
    ChartProcess(QObject *parent,const QString filePath="",QChartView *View=nullptr);
    ~ChartProcess();
    QChartView *chartView;
    QLineSeries *series;
    void beginThread();
private:
    QWidget *widget;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QThread *thread;
    DataReader *dataReader;
    QString Path;
    void slotUpdate(QVector<qreal> data);
};
#endif // CHARTPROCESS_H
