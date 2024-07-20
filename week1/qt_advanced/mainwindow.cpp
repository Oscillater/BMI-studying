// mainwindow.cpp
#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    scene = new QGraphicsScene(this);
    graphicsView = new QGraphicsView(scene, this);
    setCentralWidget(graphicsView);
    resize(1000, 1200);
    graphicsView->setFixedSize(1000, 1200);
    scene->setSceneRect(0, 0, 1000, 600);
    button = new QPushButton("PUSH ME PLEASE~", this);
    button->setGeometry(50, 50, 200, 30);
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}
MainWindow::~MainWindow(){}
void MainWindow::setWidget(QWidget *newWidget){
    container=newWidget;
}
void MainWindow::setScroll(QScrollArea *newScroll){
    scrollArea=newScroll;
}
void MainWindow::setLayout(QVBoxLayout *newlayout){
    layout=newlayout;
}
void MainWindow::onButtonClicked()
{
    container->setFixedSize(1000, 1000);
    container->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QFile file("data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        for(int i=0;i<8;i++){
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
            drawLineChart(xData, yData,i);
        }
    }
    layout->setSizeConstraint(QLayout::SetFixedSize);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 垂直滚动条按需显示
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 水平滚动条总是显示
    setCentralWidget(scrollArea);
    resize(1000, 1200);
}

QChart* MainWindow::createChart(){
    QChart *chart = new QChart();
    chart->resize(1000,300);
    chart->setTheme(QChart::ChartThemeLight);
    chart->legend()->setVisible(false);
    return chart;
};

void MainWindow::drawLineChart(const QVector<qreal> &xData, const QVector<qreal> &yData,int t)
{
    QLabel *label = new QLabel();
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    QString a1="Graph";
    QString a2=QString::number(t+1);
    QString output=a1+a2;
    label->setText(output);
    layout->addWidget(label);
    QWidget *widget=new QWidget;
    QChart *chart=createChart();
    QLineSeries *series = new QLineSeries();
    for (int i = 0; i < xData.size(); ++i) {
        series->append(xData[i], yData[i]);
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    QChartView *chartView = new QChartView(chart,widget);
    chartView->setFixedSize(1000,300);
    layout->addWidget(chartView);
}


