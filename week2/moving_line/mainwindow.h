// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datareader.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVector>
#include <QPointF>
#include <QtCharts/QSplineSeries>
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
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();

private:
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QPushButton *button;
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChart *chart;
    QChartView *chartView;
    int x_index=201;
    void drawLineChart(const QVector<qreal> &xData, const QVector<qreal> &yData);
    void timeoutHandler();
    void getNewValue();
};

#endif // MAINWINDOW_H
