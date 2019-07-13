#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"battlewindow.h"
#include"battle.h"
#include<QPaintEvent>
#include"me.h"
#include"enemy.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建战斗
    enemy *en = new enemy;
    me * p = new me;
    battlescene= new battle(en,p);


    //监听战斗返回的信号
    connect(battlescene,&battle::choosesceneback,[=](){
        battlescene->hide();
        this->show();
    });


    connect(ui->pushstart,&QPushButton::clicked,[=](){
            //将自身隐藏
            this->hide();
            //进入战斗场景
            battlescene->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
