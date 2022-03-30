#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rulespopup rulespopup;
    rulespopup.setModal(true);
    rulespopup.exec();
    MainWindow w;
    w.show();
    return a.exec();
}
