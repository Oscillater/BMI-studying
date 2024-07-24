// mainwindow.cpp
#include "mainwindow.h"

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
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);
    axisX->setTickCount(201);
    axisX->setRange(0, 200);
    axisY->setRange(0, 3);
    chart->setTheme(QChart::ChartThemeLight);
    series = new QSplineSeries();
    QTimer timer;
    chartView = new QChartView(chart);
    connect(&timer, &QTimer::timeout, this, &MainWindow::timeoutHandler);
    timer.setInterval(33);
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

    for (int i = 0; i < xData.size(); ++i) {
        series->append(xData[i], yData[i]);
    }
    chart->addSeries(series);
    series->attachAxis(axisX);
    series->attachAxis(axisY);
    chart->setTitle("MOVING LINE");
    chart->legend()->setVisible(false);
    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
}
void MainWindow::timeoutHandler(){
    QDateTime dt;
    QString current_dt = dt.currentDateTime().toString("yyyy:MM:dd:hh:mm:ss:zzz");
    qint64 ms = dt.currentDateTime().toMSecsSinceEpoch();
    time_t t = static_cast<time_t>(ms / 1000);
    srand(static_cast<uint>(t));
    int y = rand() % 3;
    series->append(x_index, y);
    if(x_index > 201)
        axisX->setRange(x_index-201, x_index);
    x_index++;
}
void MainWindow::getNewValue(){

}
