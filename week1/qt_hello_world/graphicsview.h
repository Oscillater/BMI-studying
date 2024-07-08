#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView {
    Q_OBJECT

public:
    explicit GraphicsView(QWidget *parent = nullptr);

    // 槽函数声明
public slots:
    void displayImage();
};

#endif // GRAPHICSVIEW_H
