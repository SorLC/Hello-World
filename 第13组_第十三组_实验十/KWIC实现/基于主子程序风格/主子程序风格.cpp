#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> IN, OUT;
int Num;

void Input(int& Num) //输入子程序，接收输入的文本
{
    cout << "输入短句的数量：";
    cin >> Num;
    getchar(); //去除换行符
    cout << "按行输入短句: " << endl;
    string tmp;
    for (int i = 0; i < Num; i++)
    {
        getline(cin, tmp);
        IN.push_back(tmp);
    }
}
void Shift() //替换短句内单词的次序
{
    string tmp, ans;
    for (int i = 0; i < Num; i++)
    {
        tmp = IN[i];
        int len = tmp.length();
        int pos1 = 0, pos2 = 0;
        vector<string> words;
        while (pos1 < len)
        {
            if (tmp[pos1] != ' ') {
                pos1++;
            }
            else {
                string word = tmp.substr(pos2, pos1++ - pos2);
                words.push_back(word);
                pos2 = pos1;
            }
        }
        string word = tmp.substr(pos2);
        words.push_back(word);
        int num = words.size();
        for (int i = 0; i < num; i++)
        {
            ans = "";
            for (int j = (i + 1) % num; j != i; j = (j + 1) % num)
            {
                ans = ans + words[j] + ' ';
            }
            ans += words[i];
            OUT.push_back(ans);
        }
    }
}
bool cmp(string a, string b)
{
    if (a[0] >= 'A' && a[0] <= 'Z')
    {
        if (b[0] >= 'A' && b[0] <= 'Z') {
            return a[0] < b[0];
        }
        else {
            return a[0] < b[0] - 32;
        }
    }
    else {
        if (b[0] >= 'A' && b[0] <= 'Z') {
            return a[0] - 32 < b[0];
        }
        else {
            return a[0] < b[0];
        }
    }
}
void Sort() //对输出短语排序
{
    sort(OUT.begin(), OUT.end(), cmp);
}
int main()
{
    Input(Num);
    Shift();
    Sort();
    cout << "排序结果:" << endl;
    int num = OUT.size();
    for (int i = 0; i < num; i++)
    {
        cout << OUT[i] << endl;
    }
    return 0;
}


