#ifndef OBJECT_H
#define OBJECT_H

#include "notch.h"
class Object
{
public:
    int atd,dfd,htd;
    int x,y;
    const char* pic;
    Object(int x,int y,int k,int a,int d,int h,const char*);
};

#endif // OBJECT_H
