#ifndef BATTLE_H
#define BATTLE_H

#include <QMainWindow>
#include<QPaintEvent>
#include"enemy.h"
#include"me.h"
#include"hurt.h"
#include<QSound>
namespace Ui {
class battle;
}

class battle : public QMainWindow
{
    Q_OBJECT

public:
    explicit battle(enemy *en,me * p,QWidget *parent = nullptr);
    ~battle();
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    static int hurtetom(enemy *e,me *p,int pow);
    static int hurtmtoe(me *e,enemy *p,int pow);
    void battlestart(enemy *e, me *p,int i);
    static int skill0(me *pet,enemy *e,int i);
    QSound * battlesound = new QSound(":/res/Christopher Larkin - White Defender.wav");
signals:
    void choosesceneback();
    void useskill(int i);
    void back();

private:
    Ui::battle *ui;
};

#endif // BATTLE_H
