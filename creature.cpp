#include "creature.h"
Creature::Creature(int xi,int yi,int k,int a,int d,int h,const char* p)
{
    att=a;def=d;hea=h;
    pic=p;
    x=xi;y=yi;
    occupy((x-200)/40,(y-100)/40,k);
    e.attack=att;e.fend=def;e.hp=hea;e.hprest=e.hp;
}
