#include "graphdrawer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphDrawer w;
    w.show();
    return a.exec();
}
