#include <iostream>
using namespace std;
class client {//��������
public:
	virtual void work() = 0;//�����
};

class custom {//�ͻ�
public:
	custom(client* _client){
		this->_client = _client; 
	}
	void work() {	//�������߲�ҵ���߼������㿿£
		_client->work();  
	}
private:
	client* _client;
};

//�ͻ��������ӿ�
class clientinterface : public client { //ʵ���麯����д               
public:
	void work() {//ʵ�ֲ����м����㿿£�����Զ���work��������
		cout << "������1" << endl; 
	}
};

int main(){
	client* _client = NULL;
	_client = new clientinterface;
	custom* _custom = new custom(_client);
	_custom->work();

	cout << "����" << endl;
	return 0;
}

