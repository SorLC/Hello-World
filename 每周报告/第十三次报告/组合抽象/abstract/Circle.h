#ifndef _CIRCLE_H
#define _CIRCLE_H

#include"Shape.h" 
#include "Point.h"
#include<iostream>
using namespace std;

//Circle¿‡, ºÃ≥–
class Circle:public Shape{    
	public:
		Point(Point cc = 0, int rr = 0) {
		centre = cc;
		r = rr;
	}
	virtual void show(){
    	cout<<"Circle Centre:("<<centre.x<<","<<centre.y<<")  r:"<<r<<endl;
	} 
	Point getC() { return centre; }
	int getR() { return r; }
private:
	Point centre;
	int r;
};

#endif //_CIRCLE_H
