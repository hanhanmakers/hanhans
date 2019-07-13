#include "me.h"
#include<QDebug>
#include"enemy.h"
me::me(QWidget *parent) : QWidget(parent)
{

    attack = 100;
    fend = 100;
    speed = 310;
    hp = 2000;
    hprest = 2000 ;
    attchange = 0;
    fendchange = 0;
    hurtup = 1;
    hurtdown = 1;
}


