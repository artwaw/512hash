#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationVersion("0.1");
    QCoreApplication::setOrganizationName("TrollNet");
    QCoreApplication::setOrganizationDomain("trollnet.com.pl");
    QCoreApplication::setApplicationName("512hash-gui");
    MainWindow w;
    w.show();
    return a.exec();
}
