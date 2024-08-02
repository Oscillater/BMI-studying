#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "work.h"
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
#include "qcustomplot.h"
#define POINTSNUMBER 200
#define STOPVALUE -1
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot* plot;
    QThread *thread;
    void slotUpdate(QVector<qreal> data);
    Work *work;
};
#endif // MAINWINDOW_H
