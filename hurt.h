#ifndef HURT_H
#define HURT_H
#include"enemy.h"
#include"me.h"
#include <QObject>

class hurt : public QObject
{
    Q_OBJECT
public:
    explicit hurt(QObject *parent = nullptr);
    static int hurtetom(enemy *e,me *p,int pow);
    static int hurtmtoe(enemy *e,me *p,int pow);

signals:

public slots:
};

#endif // HURT_H
