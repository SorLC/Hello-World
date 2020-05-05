#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct line{
    vector<string> _string;
};
line input_line;
vector<line> _line;

struct words{
    int _row, _column;
};
vector<words> _words;

class Input {
public:
    void in_put() {
        string _input;
        while (cin >> _input) {
            input_line._string.push_back(_input);
            if (getchar() == '\n') {
                _line.push_back(input_line);
                input_line._string.clear();
            }
        }
    }
};

bool cmp(const words& w1, const words& w2) {
    line l1, l2;
    for (int i = w1._column; i < _line[w1._row]._string.size(); i++) {
        l1._string.push_back(_line[w1._row]._string[i]);
    }
    for (int i = 0; i < w1._column; i++) {
        l1._string.push_back(_line[w1._row]._string[i]);
    }
    for (int i = w2._column; i < _line[w2._row]._string.size(); i++) {
        l2._string.push_back(_line[w2._row]._string[i]);
    }
    for (int i = 0; i < w2._column; i++) {
        l2._string.push_back(_line[w2._row]._string[i]);
    }
    int len = min((int)l1._string.size(), (int)l2._string.size());
    for (int i = 0; i < len; i++) {
        if (l1._string[i] != l2._string[i]) {
            return l1._string[i] < l2._string[i];
        }
    }
    return l1._string.size() < l2._string.size();
}

class Sort {
public:
    void operation(){
        for (int i = 0; i < _line.size(); i++) {
            for (int j = 0; j < _line[i]._string.size(); j++) {
                _words.push_back({ i, j });
            }
        }

        sort(_words.begin(), _words.end(), cmp);
    }
};

class Output {
public:
    void out_put() {
        for (int i = 0; i < _words.size(); i++) {
            int row_pos = _words[i]._row;
            int coloumn_pos = _words[i]._column;
            int _size = (int)_line[_words[i]._row]._string.size();
            int count = 0;
            for (int j = coloumn_pos; j < _size; j++) {
                count++;
                cout << _line[row_pos]._string[j] << (count == _size ? '\n' : ' ');
            }
            for (int j = 0; j < coloumn_pos; j++) {
                count++;
                cout << _line[row_pos]._string[j] << (count == _size ? '\n' : ' ');
            }
        }
    }
};

int main(){
   
    Input _in;
    _in.in_put();

    Sort _sort;
    _sort.operation();

    Output _output;
    _output.out_put();

    return 0;
}