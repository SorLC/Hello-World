#ifndef _FILTER_H_
#define _FILTER_H_

#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;

class pipe //管道类
{
public:
    vector<string> buffer;
};

void transport(pipe *p1, pipe *p2) //管道之间传输数据
{
    vector<string>::iterator p = p1->buffer.begin();
    for (; p != p1->buffer.end(); p++)
        p2->buffer.push_back(*p);
}

class filter //过滤器
{
public:
    filter(){};
    void trans();

public:
    pipe input;
    pipe output;
};

class inputFilter : public filter //文件读取过滤器
{
public:
    void read();
};

class transFilter : public filter //循环移位过滤器
{
public:
    void exchange();
};

class sortFilter : public filter //排序过滤器
{
public:
    void sortthis();
};
class outputFilter : public filter //输出过滤器
{
public:
    void put();
};

/////
bool comp(string a, string b) //字符串比较
{
    int len = a.length() > b.length() ? a.length() : b.length();
    int i = 0;
    for (i; i < len; i++)
    {
        if (a[i] == b[i])
            continue;
        else
        {
            if (a[i] == '\0' || b[i] == '\0')
            {
                if (b[i] == '\0')
                    return false;
                if (a[i] == '\0')
                    return true;
            }
            else if (a[i] == ' ' || b[i] == ' ')
            {
                if (b[i] == ' ')
                    return false;
                if (a[i] == ' ')
                    return true;
            }
            else
            {
                char ap, bp;
                if (a[i] >= 'A' && a[i] <= 'Z')
                    ap = a[i] + 32;
                else
                    ap = a[i];
                if (b[i] >= 'A' && b[i] <= 'Z')
                    bp = b[i] + 32;
                else
                    bp = b[i];
                if (bp < ap)
                    return false;
                else if (ap < bp)
                    return true;
                else
                {
                    if (a[i] >= 'A' && a[i] <= 'Z')
                        return false;
                    else
                        return true;
                }
            }
        }
    }
}


void sortFilter ::sortthis() //排序
{
    vector<string> swap = input.buffer;
    sort(swap.begin(), swap.end(), comp);
    output.buffer = swap;
}

void transFilter ::exchange() //循环左移
{
    vector<string>::iterator p = input.buffer.begin();
    for (; p != input.buffer.end(); p++)
    {
        string s = *p;
        s += " ";
        string temp = "";
        vector<string> ss;

        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                temp += s[i];
            else
            {
                cnt++;
                temp += " ";
                ss.push_back(temp);
                temp = "";
            }
        }
        string tempstr = "";
        for (int i = 0; i < cnt; i++)
        {
            tempstr = "";
            int tempchar = (i + 1) % cnt;
            for (int j = 0; j < cnt; j++)
            {

                tempstr += ss[tempchar];
                tempchar++;
                tempchar = tempchar % cnt;
            }
            tempstr[tempstr.size() - 1] = '\0';
            output.buffer.push_back(tempstr);
        }
    }
}

void inputFilter ::read() //从文件中读取
{
    string filename;
    string line, word;
    bool mark = false;
    while (!mark)
    {
        cout << "input your file name: ";
        cin >> filename;
        fstream tempfile(filename.c_str());
        if (!tempfile)
            cout << "error!" << endl;
        else
        {
            cout << "open successed!" << endl;
            while (getline(tempfile, line))
                input.buffer.push_back(line);
            mark = true;
            tempfile.close();
        }
    }
}
void filter::trans() //转化为输出数据流
{
    vector<string>::iterator p;
    for (p = input.buffer.begin(); p != input.buffer.end(); p++)
        output.buffer.push_back(*p);
}
void outputFilter::put() //将结果输出到文件中
{
    string filename;
    cout << "input the filename you want to save to:";
    cin >> filename;
    ofstream tempfile(filename.c_str());
    if (!tempfile)
    {
        cout << "error!" << endl;
    }
    else
    {
        for (vector<string>::iterator iter1 = output.buffer.begin(); iter1 != output.buffer.end(); iter1++)
        {
            tempfile << (*iter1).c_str();
            tempfile << endl;
        }
    }
    cout << "save complain!" << endl;
    tempfile.close();
}

#endif // !FILTER_H_
