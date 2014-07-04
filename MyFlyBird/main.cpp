
#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");

    MainWindow w;
    w.show();

    QRectF r1(100, 200, 11, 16);
    qDebug()<<r1.x()<<r1.y()<<r1.width()<<r1.height();
    r1.translate(-6.1,2.3);
    qDebug()<<r1.x()<<r1.y()<<r1.width()<<r1.height();
    return a.exec();
}
