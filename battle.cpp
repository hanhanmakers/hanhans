#include "battle.h"
#include "ui_battle.h"
#include<mypushbutton.h>
#include<QTimer>
#include<QPainter>
#include<QLabel>
#include<QDebug>
#include"enemy.h"
#include"me.h"
#include<stdlib.h>
#include"time.h"
#include"QMovie"
#include<QProgressBar>
#include<QMessageBox>
#include<QListWidget>
#include<QSound>
void battle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//                                                                         //背景图
    QPixmap pix,pixp,pixe;
    pix.load(":/res/background3.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pixp.load(":/res/pet.png");
    painter.drawPixmap(100,400,200,200,pixp);

}


battle::battle(enemy * en,me * p,QWidget *parent) :
    QMainWindow (parent),
    ui(new Ui::battle)
{
    ui->setupUi(this);

    ui->pro1->setValue(p->hprest);
    ui->pro2->setValue(en->hprest);
    QLabel * le = new QLabel(this);
    //设置大小
    le->setFixedSize(200,200);
    //位置
    le->move(700,400);
    QPixmap pixe;
    pixe.load(en->str);
    le->setPixmap(pixe);






    battlesound->setLoops(-1);//设置循环次数
    battlesound->play();


    //设置大小
    this->setFixedSize(1000,1000);
    //标题
    this->setWindowTitle("battle");
 //                                                                        //返回按钮创建

    mypushbutton * backbutton = new mypushbutton(":/res/quit.PNG");
    backbutton->setParent(this);
    backbutton->move(this->width()-backbutton->width(),this->height()-backbutton->height()-40);
    connect(backbutton,&mypushbutton::clicked,[=](){
        //自身隐藏,延时发信号
        if(QMessageBox::Yes==QMessageBox::question(this,"","是否退出对战？",QMessageBox::Yes|QMessageBox::No)){
        QTimer::singleShot(500,this,[=](){
            emit this->choosesceneback();
            this->back();
            battlesound->stop();
        });}

    });

//                                                                           //我方技能特效
    QLabel * label = new QLabel(this);
    //设置大小
    label->setFixedSize(200,400);
    //设置内容
    QMovie * movie= new QMovie(":/res/leishentianmingshan.gif");
    label->setMovie(movie);
    //位置
    label->move(750,270);

    QLabel * labels1 = new QLabel(this);
    //设置大小
    labels1->setFixedSize(400,400);
    //设置内容
    QMovie * movies1= new QMovie(":/res/gif3.gif");
    labels1->setMovie(movies1);
    //位置
    labels1->move(670,270);

    QLabel * labels2 = new QLabel(this);
    //设置大小
    labels2->setFixedSize(200,400);
    //设置内容
    QMovie * movies2= new QMovie(":/res/guilinglenghuo.gif");
    labels2->setMovie(movies2);
    //位置
    labels2->move(750,270);

    QLabel * labels3 = new QLabel(this);
    //设置大小
    labels3->setFixedSize(200,400);
    //设置内容
    QMovie * movies3= new QMovie(":/res/huoyanbaozha.gif");
    labels3->setMovie(movies3);
    //位置
    labels3->move(710,270);

//    int i = 0;
//    QString huihe = QString("回合数：%1").arg(i);
//    ui->labelhuihe->setText(huihe);
//    connect(skillbtn0,&mypushbutton::clicked,[=](){};




//                                                                              //技能0
    mypushbutton * skillbtn0 = new mypushbutton(":/res/skill.png",":/res/skillpress.png");
    skillbtn0->setParent(this);
    skillbtn0->setFixedSize(200,200);
    skillbtn0->move((0%4)*220,790+(0/4)*70);
    connect(skillbtn0,&mypushbutton::clicked,[=](){
        emit this->battlestart(en,p,0);
        QString strs0 = QString("【你】使用了【电闪雷鸣】，状态：【正常】");
        QListWidgetItem * items0 = new QListWidgetItem(strs0);
        ui->listWidget->addItem(items0);
        label->show();
        movie->start();
        QTimer::singleShot(1000,this,[=](){
            emit movie->stop(); label->hide();
        });
    });
    QLabel * label0 = new QLabel(this);
    //设置大小
    label0->setFixedSize(skillbtn0->width(),skillbtn0->height());
    //设置内容
    label0->setText("电闪雷鸣");
    QFont l0("微软雅黑",20);
    label0->setFont(l0);
    //位置
    label0->move((0%4)*220,790+(0/4)*70);
    label0->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //设置鼠标穿透
    label0->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透属性





//                                                                               //技能1
    mypushbutton * skillbtn1 = new mypushbutton(":/res/skill.png",":/res/skillpress.png");
    skillbtn1->setParent(this);
    skillbtn1->setFixedSize(200,200);
    skillbtn1->move((1%4)*220,790+(1/4)*70);
    connect(skillbtn1,&mypushbutton::clicked,[=](){
         emit this->battlestart(en,p,1);
        QString strs1 = QString("【你】使用了【电流爆炸】，状态：【正常】");
        QListWidgetItem * items1 = new QListWidgetItem(strs1);
        ui->listWidget->addItem(items1);
        labels1->show();
        movies1->start();

        //                                                                                            //自己恢复hp
                 QLabel * labelmy = new QLabel(this);
                 //设置大小
                 labelmy->setFixedSize(80,20);
                 //位置
                 labelmy->move(200,270);
                 labelmy->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                 labelmy->setStyleSheet("font: bold; font-size:25px; color: rgb(70, 240, 62)");
                 QString strmy = QString("+%1").arg((int)p->hp/3);
                 labelmy->setText(strmy);
                 labelmy->show();
                 QTimer::singleShot(1000,this,[=](){
                     emit labelmy->hide();delete labelmy;
                 });
        QTimer::singleShot(1000,this,[=](){
            emit movies1->stop(); labels1->hide();
        });
    });
    QLabel * label1 = new QLabel(this);
    //设置大小
    label1->setFixedSize(skillbtn1->width(),skillbtn1->height());
    //设置内容
    label1->setText("电流爆炸");
    QFont l1("微软雅黑",20);
    label1->setFont(l1);
    //位置
    label1->move((1%4)*220,790+(1/4)*70);
    label1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //设置鼠标穿透
    label1->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透属性



 //                                                                                 //技能2
    mypushbutton * skillbtn2 = new mypushbutton(":/res/skill.png",":/res/skillpress.png");
    skillbtn2->setParent(this);
    skillbtn2->setFixedSize(200,200);
    skillbtn2->move((2%4)*220,790+(2/4)*70);
    connect(skillbtn2,&mypushbutton::clicked,[=](){
        emit this->battlestart(en,p,2);
        QString strs2 = QString("【你】使用了【瀑流千击】，状态：【正常】");
        QListWidgetItem * items2 = new QListWidgetItem(strs2);
        ui->listWidget->addItem(items2);
        labels2->show();
        movies2->start();
        QTimer::singleShot(1000,this,[=](){
            emit movies2->stop(); labels2->hide();
        });
    });
    QLabel * label2 = new QLabel(this);
    //设置大小
    label2->setFixedSize(skillbtn2->width(),skillbtn2->height());
    //设置内容
    label2->setText("瀑流千击");
    QFont l2("微软雅黑",20);
    label2->setFont(l2);
    //位置
    label2->move((2%4)*220,790+(2/4)*70);
    label2->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //设置鼠标穿透
    label2->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透属性



//                                                                                    //技能3
    mypushbutton * skillbtn3 = new mypushbutton(":/res/skill.png",":/res/skillpress.png");
    skillbtn3->setParent(this);
    skillbtn3->setFixedSize(200,200);
    skillbtn3->move((3%4)*220,790+(3/4)*70);
    connect(skillbtn3,&mypushbutton::clicked,[=](){
        emit this->battlestart(en,p,3);
        QString strs3 = QString("【你】使用了【煌炎烈刃】，状态：【正常】");
        QListWidgetItem * items3 = new QListWidgetItem(strs3);
        ui->listWidget->addItem(items3);
        labels3->show();
        movies3->start();
        QTimer::singleShot(1000,this,[=](){
            emit movies3->stop(); labels3->hide();
        });
    });
    QLabel * label3 = new QLabel(this);
    //设置大小
    label3->setFixedSize(skillbtn3->width(),skillbtn3->height());
    //设置内容
    label3->setText("煌炎烈刃");
    QFont l3("微软雅黑",20);
    label3->setFont(l3);
    //位置
    label3->move((3%4)*220,790+(3/4)*70);
    label3->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //设置鼠标穿透
    label3->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透属性


}

//                                                                               //两个伤害函数
int hurtetom(enemy *e,me * pet,int pow){
    srand((unsigned)time(NULL));
    int a = (rand()%186+815);
       if(pet->fendchange>0) {
           double hurt = ((42*e->attack*pow*e->hurtup)/(pet->fend*50)+2)*1.5*(2/(2+pet->fendchange))*a/1000;
           int inthurt=hurt;
           return inthurt;
       }
       else {
           double hurt = ((42*e->attack*pow*e->hurtup)/(pet->fend*50)+2)*1.5*((2-pet->fendchange)/2)*a/1000;
           int inthurt=hurt;
           return inthurt;
       }

}

int hurtmtoe(enemy *e,me *pet,int pow){

    srand((unsigned)time(NULL));
    int a = (rand()%186+815);
       if(e->fendchange<0) {
           double hurt = ((42*pet->attack*pow*pet->hurtup)/(e->fend*50)+2)*1.5*((2-e->fendchange)/2)*a/1000;
           int inthurt=hurt;
           return inthurt;

       }
       else {
           double hurt = ((42*pet->attack*pow*pet->hurtup)/(e->fend*50)+2)*1.5*(2/(2+e->fendchange))*a/1000;
           int inthurt=hurt;
           return inthurt;
       }

}

//                                                                                 //我方技能
int battle::skill0(me *pet,enemy *e,int i)
{
    if(i==0){return 80;}
    if(i==1){ pet->hprest+=(int)(pet->hp/3);
        if(pet->hprest>pet->hp)
        {
            pet->hprest=pet->hp;
        }
        return 0;}
    if(i==2){
        return 40;}
    if(i==3){return 120;}
    else return 0;

}

//                                                                                  //战斗函数
 void battle::battlestart(enemy *e, me *p,int i)
{


//                                                                                       //敌方技能特效
         QLabel * labelx = new QLabel(this);
         //设置大小
         labelx->setFixedSize(200,400);
         //设置内容
         QMovie * moviex= new QMovie(":/res/leishentianmingshan.gif");
         labelx->setMovie(moviex);
         //位置
         labelx->move(150,270);


         QLabel * labelx1 = new QLabel(this);
         //设置大小
         labelx1->setFixedSize(400,400);
         //设置内容
         QMovie * moviex1= new QMovie(":/res/gif4.gif");
         labelx1->setMovie(moviex1);
         //位置
         labelx1->move(60,270);


         QLabel * labelx2 = new QLabel(this);
         //设置大小
         labelx2->setFixedSize(200,400);
         //设置内容
         QMovie * moviex2= new QMovie(":/res/gif6.gif");
         labelx2->setMovie(moviex2);
         //位置
         labelx2->move(150,330);


         QLabel * labelx3 = new QLabel(this);
         //设置大小
         labelx3->setFixedSize(200,400);
         //设置内容
         QMovie * moviex3= new QMovie(":/res/gif8.gif");
         labelx3->setMovie(moviex3);
         //位置
         labelx3->move(150,270);


//                                                                                                //对对方造成伤害
         QLabel * labelmyb = new QLabel(this);
         //设置大小
         labelmyb->setFixedSize(80,20);
         //位置
         labelmyb->move(790,270);
         labelmyb->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//                                                                                                //对方对本方造成伤害
         QLabel * labelenb = new QLabel(this);
         //设置大小
         labelenb->setFixedSize(80,20);
         //位置
         labelenb->move(200,270);
         labelenb->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);



//                                                                                                //核心判定
     if(p->hprest!=0)
     {

         int hh = hurt::hurtmtoe(e,p,battle::skill0(p,e,i));
         e->hprest -= hh;

         QString str = QString("-%1").arg(hh);

         labelmyb->setText(str);
         labelmyb->setStyleSheet("font: bold; font-size:25px; color: rgb(241, 70, 62)");
         labelmyb->show();

         ui->pro1->setValue(p->hprest);
         ui->pro2->setValue(e->hprest);

         QTimer::singleShot(1000,this,[=](){
             emit labelmyb->hide();delete labelmyb;
         });
         if(e->hprest<=0)
         {
             e->hprest=0;qDebug()<<"恭喜你胜利";

             ui->pro1->setValue(p->hprest);
             ui->pro2->setValue(e->hprest);
             if(QMessageBox::Ok==QMessageBox::information(this,"恭喜你","你真牛皮"))
             {
                 this->hide();
                 p->hp=p->hprest;
                 battlesound->stop();
             }
         }

         if(e->hprest!=0)
         {
             QTimer::singleShot(1500,this,[=](){
             srand((unsigned)time(NULL));
             int a = (rand()%3+0);

             if(a==0){
                 QString strene = QString("【enemy】使用了【雷裂残阳】，状态：【正常】").arg(a+1);
                 QListWidgetItem * itemene = new QListWidgetItem(strene);
                 ui->listWidget->addItem(itemene);
             }
             if(a==1){
                 QString strene = QString("【enemy】使用了【风卷残云】，状态：【正常】").arg(a+1);
                 QListWidgetItem * itemene = new QListWidgetItem(strene);
                 ui->listWidget->addItem(itemene);
             }
             if(a==2){
                 QString strene = QString("【enemy】使用了【撼地开山破】，状态：【正常】").arg(a+1);
                 QListWidgetItem * itemene = new QListWidgetItem(strene);
                 ui->listWidget->addItem(itemene);
             }
             if(a==3){
                 QString strene = QString("【enemy】使用了【天雷火烧】，状态：【正常】").arg(a+1);
                 QListWidgetItem * itemene = new QListWidgetItem(strene);
                 ui->listWidget->addItem(itemene);
             }

             int b = hurt::hurtetom(e,p,enemy::skill0(e,p,a));
             p->hprest -= b;
             ui->pro1->setValue(p->hprest);
             ui->pro2->setValue(e->hprest);

             QString str1 = QString("-%1").arg(b);


             if(a==0){


                     //                                                                                            //对手恢复hp
                     QLabel * labelen = new QLabel(this);
                     //设置大小
                     labelen->setFixedSize(80,20);
                     //位置
                     labelen->move(790,270);
                     labelen->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                     labelen->setStyleSheet("font: bold; font-size:25px; color: rgb(70, 240, 62)");
                     QString stren = QString("+%1").arg((int)e->hp/4);
                     labelen->setText(stren);
                     labelen->show();
                     QTimer::singleShot(1000,this,[=](){
                         emit labelen->hide();delete labelen;
                     });
                     labelx->show();
                     moviex->start();
                     QTimer::singleShot(1000,this,[=](){
                         emit moviex->stop(); labelx->hide();
                     });

             }
             if(a==1){


                     labelx1->show();
                     moviex1->start();
                     QTimer::singleShot(1000,this,[=](){
                         emit moviex1->stop(); labelx1->hide();
                     });

             }
             if(a==2){

                     labelx2->show();
                     moviex2->start();
                     QTimer::singleShot(1000,this,[=](){
                         emit moviex2->stop(); labelx2->hide();
                     });

             }
             if(a==3){

                     labelx3->show();
                     moviex3->start();
                     QTimer::singleShot(1000,this,[=](){
                         emit moviex3->stop(); labelx3->hide();
                     });

             }
             ui->pro1->setValue(p->hprest);
             ui->pro2->setValue(e->hprest);

                 labelenb->setStyleSheet("font: bold; font-size:25px; color: rgb(241, 70, 62)");
                 labelenb->setText(str1);
                 labelenb->show();
                 QTimer::singleShot(1000,this,[=](){
                     emit labelenb->hide();delete labelenb;
                 });
             if(p->hprest<=0)
             {
                 p->hprest=0;qDebug()<<"你输了";
                 ui->pro1->setValue(p->hprest);
                 ui->pro2->setValue(e->hprest);
                 if(QMessageBox::Ok==QMessageBox::information(this,"很遗憾","你真垃圾"))
                 {
                     this->hide();
                     battlesound->stop();
                 }
             }
             else {
                 qDebug()<<"我方还剩"<<p->hprest;
                 qDebug()<<"对方还剩"<<e->hprest<<"----------------";

//                 QString str = QString("我方还剩%1，对方还剩%2").arg(p->hprest).arg(e->hprest);
//                 QListWidgetItem * item = new QListWidgetItem(str);
//                 ui->listWidget->addItem(item);

             }
             ui->pro1->setValue(p->hprest);
             ui->pro2->setValue(e->hprest);
         });
        }
     }
     ui->pro1->setMinimum(0);
     ui->pro1->setMaximum(p->hp);
     ui->pro1->setValue(p->hprest);

     ui->pro2->setMinimum(0);
     ui->pro2->setMaximum(e->hp);
     ui->pro2->setValue(e->hprest);
}
battle::~battle()
{
    delete ui;
}
