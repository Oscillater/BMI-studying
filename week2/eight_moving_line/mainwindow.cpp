#include "mainwindow.h"
#include "chartprocess.h"
//修改方向：新建一个类专门用来画图。这个类类似于一个Widget,里面包括chart之类的组件（也就是mainwindow里面这一坨全部挪进去）
//MainWindow类则用来处理类似滚动条这样的逻辑，并且负责把这些Widget插进去。
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(1000,600);
    button = new QPushButton("点我",this);
    button->setGeometry(50,50,100,30);
    connect(button,&QPushButton::clicked,this,&MainWindow::onButtonClicked);

}

MainWindow::~MainWindow()
{
}

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
    layout->setSizeConstraint(QLayout::SetFixedSize);
    //添加
    QChartView *view1=new QChartView();
    layout->addWidget(view1);
    ChartProcess chart1(nullptr,"data.txt",view1);
    chart1.chartView->setFixedSize(1000,300);
    chart1.beginThread();
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 垂直滚动条按需显示
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn); // 水平滚动条总是显示
    setCentralWidget(scrollArea);
    layout->addWidget(chart1.chartView);
    QThread::sleep(5000);
}
