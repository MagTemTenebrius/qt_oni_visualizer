#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <OpenNI.h>

int main(int argc, char *argv[]) {
    std::cout << "Test";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
