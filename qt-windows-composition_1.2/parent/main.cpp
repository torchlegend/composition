#include "parentwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ParentWidget s;
    s.show();

    return a.exec();
}
