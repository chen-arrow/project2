#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    LoadQss::loadQss("/qss/origin.qss");
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
