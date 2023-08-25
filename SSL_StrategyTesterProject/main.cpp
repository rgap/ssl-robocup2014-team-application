#include <QApplication>
//#include "mainwindow.h"

#include "udpgamecontroldialog.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPGameControlDialog w;
    w.show();

    return a.exec();//  a.exec();
}
