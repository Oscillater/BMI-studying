#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "datareader.h"
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
#define POINTSNUMBER 200
#define STOPVALUE -1

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setWidget(QWidget *newWidget);
    void setScroll(QScrollArea *newScroll);
    void setLayout(QVBoxLayout *layout);
public slots:
    void onButtonClicked();
private:
    QPushButton *button;
    QScrollArea *scrollArea;
    QWidget *container;
    QVBoxLayout *layout;
};
#endif // MAINWINDOW_H
