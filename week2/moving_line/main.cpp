//main.cpp
#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString filePath="data.txt";
    MainWindow mainWindow(nullptr,filePath);
    mainWindow.show();
    return app.exec();
}
