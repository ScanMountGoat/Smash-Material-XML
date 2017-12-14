#include "Headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // enable support for high DPI displays
    // this needs to be first
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
