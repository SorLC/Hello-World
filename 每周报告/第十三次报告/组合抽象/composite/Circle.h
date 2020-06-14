#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <iostream>
#include "Point.h" 
using namespace std;

class Circle
{
public: 
    Circle(Point o,int r)
    {
        O = o;
        R = r;
    }
    void show()
    {
        cout<<"Circle center:("<<O.getX()<<","<<O.getY()<<"),radius:"<<R<<endl;
    }
    int getR()
    {
        return R;
    }
private:
    Point O;
    int R;
};

#endif