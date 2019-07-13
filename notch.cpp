#include "notch.h"

Notch::Notch(int xi,int yi,int ki)
{
    x=xi;y=yi;kind=ki;
}
Notch::Notch(Notch& m)
{
    x=m.x;y=m.y;kind=m.kind;
}
void occupy(int a,int b,int c)
{
    n[a][b].kind=c;
}
