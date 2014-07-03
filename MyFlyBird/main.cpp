
#include <QApplication>
#include "mainwindow.h"
#include <QDebug>
#include <blockpipe.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");

    MainWindow w;
    w.show();

//    BlockPipe b;
//    b.show();

    return a.exec();
}
