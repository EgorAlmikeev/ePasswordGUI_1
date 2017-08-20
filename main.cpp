#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setMinimumSize(700, 523);
    w.setMaximumSize(700, 523);
    w.setWindowTitle("ePassword");
    w.show();
    w.setFocus();
    w.setGeometry(400, 200, 700, 523);
    w.processRefreshScrollArea();

    return a.exec();
}
