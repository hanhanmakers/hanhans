#ifndef CREATURE_H
#define CREATURE_H
#include "enemy.h"
#include "notch.h"
class Creature
{
public:
    enemy e;
    int att,def,hea,x,y;
    const char* pic;
    Creature(int x,int y,int k,int a,int d,int h,const char*);
};

#endif // CREATURE_H
