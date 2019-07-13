#ifndef ME_H
#define ME_H

#include <QWidget>

class me : public QWidget
{
    Q_OBJECT
public:
    explicit me(QWidget *parent = nullptr);
    int attack;
    int fend;
    int speed;
    int hp;
    int hprest;
    int attchange;
    int fendchange;
    double hurtup;
    double hurtdown;



signals:

public slots:
};

#endif // ME_H
