#include "hurt.h"

hurt::hurt(QObject *parent) : QObject(parent)
{

}
//两个伤害函数
int hurt::hurtetom(enemy *e,me * pet,int pow){
    srand((unsigned)time(NULL));
    int a = (rand()%186+815);
       if(pet->fendchange>0) {
           double hurt = (42*e->attack*pow*e->hurtup/(pet->fend*50)+2)*1*1.5*(2+pet->fendchange)/2*a/1000;
           int inthurt=hurt;
           return inthurt;
       }
       else {
           double hurt = (42*e->attack*pow*e->hurtup/(pet->fend*50)+2)*1*1.5*2/(2-pet->fendchange)*a/1000;
           int inthurt=hurt;
           return inthurt;
       }
}

int hurt::hurtmtoe(enemy *e,me *pet,int pow){
    srand((unsigned)time(NULL));
    int a = (rand()%186+815);
       if(pet->fendchange>0) {
           double hurt = (42*pet->attack*pow*pet->hurtup/(e->fend*50)+2)*1*1.5*(2+e->fendchange)/2*a/1000;
           int inthurt=hurt;
           return inthurt;
       }
       else {
           double hurt = (42*pet->attack*pow*pet->hurtup/(e->fend*50)+2)*1*1.5*2/(2-e->fendchange)*a/1000;
           int inthurt=hurt;
           return inthurt;
       }
}
