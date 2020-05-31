//������������� 

#include "Point.h"
#include "Line.h" 
#include "Rectangle.h" 
#include "Circle.h"
#include "UI.h"


//����������
int main(){ 
	UI ui;
	
	Point p1(1,2),p2(7,8);      //��������� 
	ui.pointVector.push_back(p1);
	ui.pointVector.push_back(p2);
		
	Line line1(p1,p2);         //�߶��� 
	ui.lineVector.push_back(line1);
	
	Rectangle rect1(p1,5,6);   //���ζ��� 
	ui.rectVector.push_back(rect1);

	Circle cir1(p1,3); //Բ�ζ���
	ui.circleVector.push_back(cir1);
	
    ui.show();      //������ʾ 
	
    return 0;  
}
