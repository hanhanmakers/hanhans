#include "enterdialog.h"
#include "ui_enterdialog.h"
#include <QPushButton>
#include "game.h"
EnterDialog::EnterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterDialog)
{
    ui->setupUi(this);
}

EnterDialog::~EnterDialog()
{
    delete ui;
}
void EnterDialog::buildgame()
{
    connect(ui->start,&QPushButton::clicked,[=](){
        Game *g = new Game;
        g->show();
        this->hide();
    });
}
