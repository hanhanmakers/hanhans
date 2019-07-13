#include "hero.h"

Hero::Hero(int xi,int yi)
{
    x=xi;y=yi;att=100;def=100;hea=2000;
}
void Hero::pickup(Object &o)
{
    att+=o.atd;
    def+=o.dfd;
    hea+=o.htd;
    n[(o.x-200)/40][(o.y-100)/40].kind=0;
    m.hp=hea;m.attack=att;m.fend=def;m.hprest=hea;
}
void Hero::update()
{
    hea=m.hp;
}
