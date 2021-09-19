#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>
using namespace std;
int if_else_num = 0;
int if_else_if_else_num = 0;
//栈设计
stack<char> sta;
void sta_input(char c)
{
    switch (c)
    {
    case '}':
        while (sta.top() != '{')
        {
            sta.pop();
        }
        sta.pop();
        break;
    case '{':
        sta.push('{');
        break;
    case '1':
        sta.push('1');
        break;
    case '2':
        sta.push('2');
        break;
    case '3':
        int count = 0;
        while (sta.top() != '1')
        {
            ++count;
            sta.pop();
        }
        sta.pop();
        if (count > 0)
            ++if_else_if_else_num;
        else
            ++if_else_num;
        break;
    default:
        cout << "字符输入错误" << endl;
        break;
    }
}
int main()
{
}