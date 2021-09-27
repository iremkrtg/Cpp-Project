#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Repository* repo = new Repository(10);
    Repository* list = new Repository(10);
    std::stack<Operation> undo;
    std::stack<Operation> redo;

    Controller* ctrl = new Controller(repo, list, undo, redo);

    QApplication a(argc, argv);
    MainWindow w(ctrl);
    w.show();
    return a.exec();
}
