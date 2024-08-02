// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVector>
#include <QPointF>
#include <QSplitter>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QGraphicsLineItem>
#include <QRegularExpression>
#include<QString>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QSplitter>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QString>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setWidget(QWidget *newWidget);
    void setScroll(QScrollArea *newScroll);
    void setLayout(QVBoxLayout *layout);

private slots:
    void onButtonClicked();

private:
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QPushButton *button;
    QScrollArea *scrollArea;
    QWidget *container;
    QVBoxLayout *layout;
    void drawLineChart(const QVector<qreal> &xData, const QVector<qreal> &yData,int t);
    QChart *createChart();
};

#endif // MAINWINDOW_H
