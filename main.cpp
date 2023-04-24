#include "mainwindow.h"
#include <QApplication>
#include <QSharedMemory>


int main(int argc, char *argv[])
{
    QSharedMemory sm("HMI");					// create shared memory
    if(!sm.create(8, QSharedMemory::ReadWrite)) return 0;   	// check if shared memory exist exit the application

    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
