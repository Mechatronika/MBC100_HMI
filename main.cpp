#include "mainwindow.h"
#include <QApplication>
#include <QSharedMemory>


int main(int argc, char *argv[])
{
    QSharedMemory sm("HMI");
    if(!sm.create(8, QSharedMemory::ReadWrite)) return 0;   

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
