#include "object.h"

Object::Object(int xi,int yi,int k,int a,int d,int h,const char* p)
{
    x=xi;y=yi;
    occupy((x-200)/40,(y-100)/40,k);
    atd=a;dfd=d;htd=h;pic=p;
}
