// mainwindow.cpp
#include "mainwindow.h"
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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    graphicsView = new QGraphicsView(scene, this);
    setCentralWidget(graphicsView);
    resize(1000, 600);
    graphicsView->setFixedSize(1000, 600);
    scene->setSceneRect(0, 0, 1000, 600);
    button = new QPushButton("点我~", this);
    button->setGeometry(50, 50, 100, 30);
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}
MainWindow::~MainWindow(){}
void MainWindow::onButtonClicked()
{
    QFile file("data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QVector<qreal> xData, yData;
        QString line = in.readLine();
        QStringList numbers = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        foreach (const QString &number, numbers) {
            qreal value = number.toDouble();
            xData.append(value);

        }
        line = in.readLine();
        numbers = line.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        foreach (const QString &number, numbers) {
            qreal value = number.toDouble();
            yData.append(value);
        }
        if (xData.size() != yData.size()) {
            qDebug() << "The number of x values does not match the number of y values.";
            return;
        }
        file.close();
        drawLineChart(xData, yData);
    }
}

void MainWindow::drawLineChart(const QVector<qreal> &xData, const QVector<qreal> &yData)
{
    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeLight);
    QLineSeries *series = new QLineSeries();
    for (int i = 0; i < xData.size(); ++i) {
        series->append(xData[i], yData[i]);
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Hello World");
    chart->legend()->setVisible(false);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}
