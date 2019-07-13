#include "enemy.h"
#include"me.h"
#include<QDebug>
enemy::enemy(QWidget *parent) : QWidget(parent)
{

    attack = 300;
    fend = 200;
    speed = 200;
    hp = 1000;
    hprest = hp ;
    hurtup = 1;
    hurtdown = 1;
    attchange=0;
    fendchange=0;
    QString str = ":/res/enemy1.png" ;
    QString strskill0 = ":/res/leishentianmingshan.gif";
    QString strskill1 = ":/res/gif4.gif";
    QString strskill2 = ":/res/gif6.gif";
    QString strskill3 = ":/res/gif8.gif";

}


int enemy::skill0(enemy *e,me *pet,int i)
{
    if(i==0){e->hprest+=(e->hp/4);
        if(e->hprest>e->hp){e->hprest=e->hp;}
        qDebug()<<"enemy使用了恢复！";
        return 0;}
    if(i==1){qDebug()<<"enemy使用了技能2！";
        return 100;}
    if(i==2){
        qDebug()<<"enemy使用了技能3！";
        return 90;}
    if(i==3){
        qDebug()<<"enemy使用了技能4！";
        return 80;}
    else return 0;

}

