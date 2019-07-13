#ifndef NOTCH_H
#define NOTCH_H


class Notch
{
public:
    int x,y,kind;
    Notch(int x=0,int y=0,int ki=0);
    Notch(Notch&);
};
static Notch n[15][15];
void occupy(int,int,int);
#endif // NOTCH_H
