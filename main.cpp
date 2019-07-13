#include "game.h"
#include <QApplication>
#include "enterdialog.h"
#include<QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnterDialog d;
    d.show();
//    EnterDialog* dp = &d;
    d.buildgame();
    return a.exec();
}
