//抽象设计例子 
#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 
#include "UI.h"
#include "Circle.h" 
main(){ 
	UI ui;
	 
	Point p1(1,2),p2(7,8);
	ui.shapeVector.push_back(&p1);
	ui.shapeVector.push_back(&p2);
		
	ui.shapeVector.push_back(new Line(p1,p2));
	
	ui.shapeVector.push_back(new Rectangle(p1,5,6));
	
	ui.shapeVector.push_back(new Piont(5, 6), 7);

    ui.show();
}
 
