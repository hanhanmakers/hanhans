#ifndef HERO_H
#define HERO_H
#include "me.h"
#include "object.h"
class Hero
{
public:
    me m;
    Hero(int ,int );
    int att,def,hea,x,y,key;
    void pickup(Object& o);
    void update();
};

#endif // HERO_H
