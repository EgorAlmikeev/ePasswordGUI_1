#include "mainwindow.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(700, 523);
    w.setWindowTitle("ePassword");
    w.show();
    w.setFocus();
    w.setGeometry(400, 200, 700, 523);
    w.processRefreshScrollArea();
//    w.setWindowIcon(QIcon(":/icon.icns"));

    return a.exec();
}
