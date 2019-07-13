#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include"me.h"
class enemy : public QWidget
{
    Q_OBJECT
public:
    explicit enemy(QWidget *parent = nullptr);
    int attack;
    int fend;
    int speed;
    int hp;
    int hprest;
    int attchange;
    int fendchange;
    double hurtup;
    double hurtdown;
    static  int skill0(enemy * e,me *pet,int i);
    QString str = ":/res/enemy1x.png" ;
    QString strskill0 = ":/res/leishentianmingshan.gif";
    QString strskill1 = ":/res/gif4.gif";
    QString strskill2 = ":/res/gif6.gif";
    QString strskill3 = ":/res/gif8.gif";
//    int skill1(me & pet);
//    int skill2(me & pet);
//    int skill3(me & pet);



signals:

public slots:
};

#endif // ENEMY_H
