#include "tracker.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(434,372);
    w.setStyleSheet("background-color:black;");
    w.show();

    return a.exec();
}
