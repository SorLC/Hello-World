#include <iostream>
using namespace std;
class client {//服务器类
public:
	virtual void work() = 0;//抽象层
};

class custom {//客户
public:
	custom(client* _client){
		this->_client = _client; 
	}
	void work() {	//工作，高层业务逻辑向抽象层靠拢
		_client->work();  
	}
private:
	client* _client;
};

//客户服务器接口
class clientinterface : public client { //实现虚函数重写               
public:
	void work() {//实现层向中间抽象层靠拢，所以都是work（）函数
		cout << "服务器1" << endl; 
	}
};

int main(){
	client* _client = NULL;
	_client = new clientinterface;
	custom* _custom = new custom(_client);
	_custom->work();

	cout << "启动" << endl;
	return 0;
}

