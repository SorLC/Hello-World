#include<iostream>
using namespace std;

#define happen cin//���巢���¼�Ϊ����

int t = 0;




bool getnumber(int t)//���¼����жϣ����Ƿ�Ϊż��
{
	if (t%2 == 0)
	{
		return true;
	}
	else
		return false;
}


void  deal(int n)//���������¼�
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