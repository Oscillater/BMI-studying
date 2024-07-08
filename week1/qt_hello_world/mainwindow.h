// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVector>
#include <QPointF>

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
    void drawLineChart(const QVector<qreal> &xData, const QVector<qreal> &yData);
};

#endif // MAINWINDOW_H
