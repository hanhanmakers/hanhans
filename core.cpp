#include "core.h"
#include "notch.h"
Core::Core(int xi,int yi,int k)
{
    x=xi;y=yi;
    occupy(x,y,k);
}
