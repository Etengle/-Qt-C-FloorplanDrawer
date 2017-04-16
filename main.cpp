#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create a QApplication whose constructor requires
    // argc and argv to be parameters
    QApplication a(argc, argv);
    // MainWindow Object Instantiation
    MainWindow w;
    // Show the main window
    w.show();

    // Enter an event loop and wait for users' action
    return a.exec();
}
