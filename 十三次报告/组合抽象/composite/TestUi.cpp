//类的组合设计例子 

#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 
#include "Circle.h"
#include "UI.h"


//测试类的组合
int main(){ 
	UI ui;
	
	Point p1(1,2),p2(7,8);      //两个点对象 
	ui.pointVector.push_back(p1);
	ui.pointVector.push_back(p2);
		
	Line line1(p1,p2);         //线对象 
	ui.lineVector.push_back(line1);
	
	Rectangle rect1(p1,5,6);   //矩形对象 
	ui.rectVector.push_back(rect1);

	Circle cir1(p1,3); //圆形对象
	ui.circleVector.push_back(cir1);
	
    ui.show();      //界面显示 
	
    return 0;  
}
