#pragma once
#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int if_else_num = 0;
int if_else_if_else_num = 0;
//栈设计
stack<char> sta;
void sta_input(char c)
{
    if (sta.empty())
    {
        sta.push(c);
        return;
    }
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
    }
}
void if_else(ifstream &input)
{
    string str;
    while (getline(input, str))
    {
        auto cur = begin(str);
        while (cur != end(str))
        {
            //去空格
            while (*cur == ' ')
            {
                ++cur;
            }
            //判断是不是ifelse
            if (isalnum(*cur))
            {
                if (str.substr(cur - begin(str), 2) == "if")
                {
                    sta_input('1');
                    cur += 2;
                }
                else if (str.substr(cur - begin(str), 4) == "else")
                {
                    if (str.substr(cur - begin(str), 7) == "else if")
                    {
                        sta_input('2');
                        cur += 7;
                    }
                    else
                    {
                        sta_input('3');
                        cur += 4;
                    }
                }
                else
                {
                    while (isalnum(*cur))
                    {
                        cur++;
                    }
                }
            }
            //判断符号
            else if (*cur == '{')
            {
                sta_input('{');
                ++cur;
            }
            else if (*cur == '}')
            {
                sta_input('}');
                ++cur;
            }
            else
                ++cur;
        }
    }
    //cout << "if_else_if_else_num" << if_else_if_else_num << endl;
    //cout << "if_else_num" << if_else_num << endl;
}
