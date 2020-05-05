#include<iostream>
using namespace std;

#define happen cin//定义发生事件为输入

int t = 0;




bool getnumber(int t)//对事件的判断，数是否为偶数
{
	if (t%2 == 0)
	{
		return true;
	}
	else
		return false;
}


void  deal(int n)//处理发生的事件
{
	cout << n;
	if (getnumber(n) )
	{
		t++;
	}
	cout << t<<endl;
}


int main()
{
	int m= 0;
	happen>> m;
	deal(m);
	return 0;
}