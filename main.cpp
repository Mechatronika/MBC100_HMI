#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mw;
    mw.showFullScreen();
    return app.exec();
}
