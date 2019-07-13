#include "game.h"
#include "ui_game.h"
#include <QKeyEvent>
#include <QSound>
#include "battle.h"
#include<QDebug>
Game::Game(QWidget *parent) :
    QWidget(parent),hero(200,660),
    mon1(360,100,2,100,100,600,":resources/pic/mon1l.png"),
    mon2(560,100,6,200,100,900,":resources/pic/mon2.png"),
    mon3(240,300,7,200,100,200,":resources/pic/mon3.png"),
    mon4(640,420,8,200,200,200,":resources/pic/mon4.png"),
    boss(640,540,9,500,200,1000,":resources/pic/BOSS.png"),
    sword(480,100,3,500,0,0,":resources/pic/attack.png"),
    shield(200,100,4,0,50,0,":resources/pic/defence.png"),
    water(760,100,5,0,0,5000,":resources/pic/water.png"),
    ui(new Ui::Game)
{
    qDebug()<<"build";
    QSound* sing=new QSound("",this);
    sing->setLoops(-1);
    setFocus();
    ui->setupUi(this);
    ui->he->resize(40,40);
    ui->he->setPixmap(QPixmap(":resources/pic/back.png"));
    ui->he->move(hero.x,hero.y);
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            Notch m(200+i*40,100+j*40,0);
            n[i][j]=m;
        }
    }
    ui->mon1l->move(mon1.x,mon1.y);
    ui->mon1l->setPixmap(QPixmap(mon1.pic));
    ui->swordl->move(sword.x,sword.y);
    ui->swordl->setPixmap(QPixmap(sword.pic));
    ui->shieldl->move(shield.x,shield.y);
    ui->shieldl->setPixmap(QPixmap(shield.pic));
    ui->waterl->move(water.x,water.y);
    ui->waterl->setPixmap(QPixmap(water.pic));
    ui->mon2l->move(mon2.x,mon2.y);
    ui->mon2l->setPixmap(QPixmap(mon2.pic));
    ui->mon3l->move(mon3.x,mon3.y);
    ui->mon3l->setPixmap(QPixmap(mon3.pic));
    ui->mon4l->move(mon4.x,mon4.y);
    ui->mon4l->setPixmap(QPixmap(mon4.pic));
    ui->bossl->move(boss.x,boss.y);
    ui->bossl->setPixmap(QPixmap(boss.pic));
    for(int i=1;i<5;i++)
    {
        n[4][i].kind=1;
        n[9][i].kind=1;
    }
    for(int i=0;i<5;i++)
    {
        n[i][4].kind=1;
    }
    for(int i=9;i<15;i++)
    {
        n[i][4].kind=1;
    }
    for(int i=0;i<5;i++)
    {
        n[i][7].kind=1;
    }
    for(int i=9;i<15;i++)
    {
        n[i][7].kind=1;
    }
    for(int i=9;i<15;i++)
    {
        n[4][i].kind=1;
    }
    for(int i=9;i<15;i++)
    {
        n[9][i].kind=1;
    }
    for(int i=5;i<9;i++)
    {
        n[i][9].kind=1;
    }
    n[11][9].kind=0;
    for(int i=9;i<15;i++)
    {
        n[i][9].kind=1;
    }
    n[11][9].kind=0;
    n[1][6].kind = 1;
    for(int i=11;i<14;i++)
    {
        for(int j=i+1;j<15;j++)
            n[i][j].kind=9;
    }
    n[4][0].kind=2;
    n[9][0].kind=6;
    n[1][5].kind=7;
    n[11][8].kind=8;
    n[7][0].kind=3;
    n[0][0].kind=4;
    n[14][0].kind=5;
    show();
    QString q=QString("%1").arg(hero.hea);
    ui->health->setText(q);
    sing->play();
}


Game::~Game()
{
    delete ui;
}
void Game::keyPressEvent(QKeyEvent *e)
{
    QSound*singa=new QSound(":resources/pic/benpao1.wav",this);
    QSound*singb=new QSound(":resources/pic/zhuang.wav",this);
    singa->setLoops(1);
    singb->setLoops(1);
    if(e->key()==Qt::Key_Up){
        if(hero.y<140) {}
        else{
            hero.y-=40;
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==0)
        {
            //跑步音效
            singa->play();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==1)
        {
            hero.y+=40;//撞墙音效
            singb->play();
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==2)
        {
            battle* b = new battle(&mon1.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[4][0].kind=0;
            ui->mon1l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y+=40;
               ui->he->move(hero.x,hero.y);
               n[4][0].kind=2;
               ui->mon1l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==3)
        {
            hero.pickup(sword);
            ui->swordl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==4)
        {
            hero.pickup(shield);
            ui->shieldl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==5)
        {
            hero.pickup(water);
            ui->waterl->setVisible(false);
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==6)
        {

            battle* b = new battle(&mon2.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[9][0].kind=0;
            ui->mon2l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y+=40;
               ui->he->move(hero.x,hero.y);
               n[9][0].kind=6;
               ui->mon2l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==7)
        {

            battle* b = new battle(&mon3.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[1][5].kind=0;
            ui->mon3l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y+=40;
               ui->he->move(hero.x,hero.y);
               n[1][5].kind=7;
               ui->mon3l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==8)
        {

            battle* b = new battle(&mon4.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[11][8].kind=0;
            ui->mon4l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y+=40;
               ui->he->move(hero.x,hero.y);
               n[11][8].kind=8;
               ui->mon4l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==9)
        {

            battle* b = new battle(&boss.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";

            for(int i=11;i<14;i++)
            {
                for(int j=i+1;j<15;j++)
                {
                    n[i][j]=0;
                }
            }
            ui->bossl->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y+=40;
               ui->he->move(hero.x,hero.y);
               for(int i=11;i<14;i++)
               {
                   for(int j=i+1;j<15;j++)
                   {
                       n[i][j]=9;
                   }
               }
               ui->bossl->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==10)
        {

            ui->he->move(hero.x,hero.y);

        }}
    }
    if(e->key()==Qt::Key_Down){
        if(hero.y>=660) {}
        else{
            hero.y+=40;
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==0)
        {
            //跑步音效
            singa->play();

            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==1)
        {
            hero.y-=40;
            //撞墙音效
            singb->play();
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==2)
        {

            battle* b = new battle(&mon1.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            n[4][0].kind=0;
            ui->mon1l->setVisible(false);
            qDebug()<<"ok";
            connect(b,&battle::back,[=](){
                b->close();
               hero.y-=40;
               ui->he->move(hero.x,hero.y);
               n[4][0].kind=2;
               ui->mon1l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==3)
        {

            hero.pickup(sword);
            ui->swordl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==4)
        {

            hero.pickup(shield);
            ui->shieldl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==5)
        {

            hero.pickup(water);
            ui->waterl->setVisible(false);
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==6)
        {

            battle* b = new battle(&mon2.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[9][0].kind=0;
            ui->mon2l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y-=40;
               ui->he->move(hero.x,hero.y);
               n[9][0].kind=6;
               ui->mon2l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==7)
        {

            battle* b = new battle(&mon3.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[1][5].kind=0;
            ui->mon3l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y-=40;
               ui->he->move(hero.x,hero.y);
               n[1][5].kind=7;
               ui->mon3l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==8)
        {

            battle* b = new battle(&mon4.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[11][8].kind=0;
            ui->mon4l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y-=40;
               ui->he->move(hero.x,hero.y);
               n[11][8].kind=8;
               ui->mon4l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==9)
        {

            battle* b = new battle(&boss.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";

            for(int i=11;i<14;i++)
            {
                for(int j=i+1;j<15;j++)
                {
                    n[i][j]=0;
                }
            }
            ui->bossl->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.y-=40;
               ui->he->move(hero.x,hero.y);
               for(int i=11;i<14;i++)
               {
                   for(int j=i+1;j<15;j++)
                   {
                       n[i][j]=9;
                   }
               }
               ui->bossl->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==10)
        {


        }
        }
    }
    if(e->key()==Qt::Key_Left){
        if(hero.x<240) {}
        else{
            hero.x-=40;
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==0)
        {
            //跑步音效
            singa->play();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==1)
        {
            hero.x+=40;
            singb->play();
            qDebug()<<"zhuangqiang";
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==2)
        {

            battle* b = new battle(&mon1.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            n[4][0].kind=0;
            ui->mon1l->setVisible(false);
            qDebug()<<"ok";
            connect(b,&battle::back,[=](){
                b->close();
               hero.x+=40;
               ui->he->move(hero.x,hero.y);
               n[4][0].kind=2;
               ui->mon1l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==3)
        {

            hero.pickup(sword);
            ui->swordl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==4)
        {

            hero.pickup(shield);
            ui->shieldl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==5)
        {

            hero.pickup(water);
            ui->waterl->setVisible(false);
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==6)
        {

            battle* b = new battle(&mon2.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[9][0].kind=0;
            ui->mon2l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x+=40;
               ui->he->move(hero.x,hero.y);
               n[9][0].kind=6;
               ui->mon2l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==7)
        {

            battle* b = new battle(&mon3.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[1][5].kind=0;
            ui->mon3l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x+=40;
               ui->he->move(hero.x,hero.y);
               n[1][5].kind=7;
               ui->mon3l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==8)
        {

            battle* b = new battle(&mon4.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[11][8].kind=0;
            ui->mon4l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x+=40;
               ui->he->move(hero.x,hero.y);
               n[11][8].kind=8;
               ui->mon4l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==9)
        {

            battle* b = new battle(&boss.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";

            for(int i=11;i<14;i++)
            {
                for(int j=i+1;j<15;j++)
                {
                    n[i][j]=0;
                }
            }
            ui->bossl->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x+=40;
               ui->he->move(hero.x,hero.y);
               for(int i=11;i<14;i++)
               {
                   for(int j=i+1;j<15;j++)
                   {
                       n[i][j]=9;
                   }
               }
               ui->bossl->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==10)
        {

            ui->he->move(hero.x,hero.y);
        }
        }

    }
    if(e->key()==Qt::Key_Right){
        if(hero.x>=760) {}
        else{
            hero.x+=40;
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==0)
        {
            //跑步音效
            singa->play();
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==1)
        {
            hero.x-=40;
            //撞墙音效
            singb->play();
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==2)
        {

            battle* b = new battle(&mon1.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[4][0].kind=0;
            ui->mon1l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x-=40;
               ui->he->move(hero.x,hero.y);
               n[4][0].kind=2;
               ui->mon1l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==3)
        {

            hero.pickup(sword);
            ui->swordl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==4)
        {

            hero.pickup(shield);
            ui->shieldl->setVisible(false);
            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==5)
        {

            hero.pickup(water);
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            ui->waterl->setVisible(false);

            ui->he->move(hero.x,hero.y);
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==6)
        {

            battle* b = new battle(&mon2.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[9][0].kind=0;
            ui->mon2l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x-=40;
               ui->he->move(hero.x,hero.y);
               n[9][0].kind=6;
               ui->mon2l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==7)
        {

            battle* b = new battle(&mon3.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[1][5].kind=0;
            ui->mon3l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x-=40;
               ui->he->move(hero.x,hero.y);
               n[1][5].kind=7;
               ui->mon3l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==8)
        {

            battle* b = new battle(&mon4.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";
            n[11][8].kind=0;
            ui->mon4l->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x-=40;
               ui->he->move(hero.x,hero.y);
               n[11][8].kind=8;
               ui->mon4l->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==9)
        {

            battle* b = new battle(&boss.e,&hero.m);
            b->show();
            ui->he->move(hero.x,hero.y);
            hero.update();
            QString q=QString("%1").arg(hero.hea);
            ui->health->setText(q);
            ui->health->show();
            qDebug()<<"ok";

            for(int i=11;i<14;i++)
            {
                for(int j=i+1;j<15;j++)
                {
                    n[i][j]=0;
                }
            }
            ui->bossl->setVisible(false);
            connect(b,&battle::back,[=](){
                b->close();
               hero.x-=40;
               ui->he->move(hero.x,hero.y);
               for(int i=11;i<14;i++)
               {
                   for(int j=i+1;j<15;j++)
                   {
                       n[i][j]=9;
                   }
               }
               ui->bossl->setVisible(true);
            });
        }
        if(n[(hero.x-200)/40][(hero.y-100)/40].kind==10)
        {

            ui->he->move(hero.x,hero.y);

        }
        }
    }
}
