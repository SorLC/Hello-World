#define _CRT_SCURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<vector>
class AbstractBuild //楼盘基类
{
public:
    AbstractBuild() {}
    virtual void sale() = 0; //模拟卖出
    virtual string getqulity() = 0; //获取该楼盘的品质

};

class BuildA :public AbstractBuild {

public:
    BuildA() {
        mqulity = "高品质";
    }
    virtual void sale() {

        cout << mqulity << endl;
    }
    virtual string getqulity() {
        return mqulity;
    }
public:
    string mqulity;

};
class BuildC :public AbstractBuild {

public:
    BuildC() {
        mqulity = "低品质";
    }
    virtual void sale() { 

        cout << mqulity << endl;
    }
    virtual string getqulity() {
        return mqulity;
    }
public:
    string mqulity;

};

//中介类
class Mediator {
public:
    Mediator() {
        AbstractBuild* d1 = new BuildA;
        Vbuild.push_back(d1);
        AbstractBuild* d2 = new BuildC;
        Vbuild.push_back(d2);
    }
    //对外提供接口
    AbstractBuild* findmybuild(string p) {
        for (vector<AbstractBuild*>::iterator it1 = Vbuild.begin(); it1 != Vbuild.end(); it1++)
        {
            if ((*it1)->getqulity() == p)
            {
                return *it1;
            }

        }
        return NULL;
    }
    ~Mediator() {
        for (vector<AbstractBuild*>::iterator it = Vbuild.begin(); it != Vbuild.end(); it++)
        {
            if (*it != NULL)
            {
                delete* it;
            }

        }
    }
public:
    vector<AbstractBuild*> Vbuild;
};
//客户端
void test(void)
{
    Mediator* mediator = new Mediator;
    AbstractBuild* D = mediator->findmybuild("高品质");
    if (D != NULL)
    {
        D->sale();
    }
    else
    {
        cout << "楼盘没有找到" << endl;
    }
}
int main(void) {
    //迪米特原则 最小知识原则

    test();
    return 0;
}