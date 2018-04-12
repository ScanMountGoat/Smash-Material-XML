#include "gui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    // Enables proper scaling for high DPI displays. Tested with Surface Pro 4 on Win10/Ubuntu.
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
