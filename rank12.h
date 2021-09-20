//rank12的实现


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
class Input_KeyWords
{
    ifstream input;
    unordered_set<string> key_set;

public:
    Input_KeyWords(string f)
    {
        input.open(f);
    }
    unordered_set<string> &read()
    {
        while (!input.eof())
        {
            string temp;
            input >> temp;
            key_set.insert(temp);
        }
        return key_set;
    }
};
class Count
{
    int total_num = 0;
    int switch_num = 0;
    int case_num = 0;
    vector<int> cases;
    ifstream input;

public:
    Count(string f)
    {
        input.open(f);
    }
    string handle_oneWord()
    {
        string temp;
        input >> temp;
        int cur;
        if ((cur = temp.find('(')) != temp.npos)
        {
            temp = temp.substr(0, cur);
        }
        else if ((cur = temp.find('{')) != temp.npos)
        {
            temp = temp.substr(0, cur);
        }
        else if ((cur = temp.find(';')) != temp.npos)
        {
            temp = temp.substr(0, cur);
        }
        else if ((cur = temp.find(':')) != temp.npos)
        {
            temp = temp.substr(0, cur);
        }
        return temp;
    }
    void count_total(unordered_set<string> &key_set) //输入关键词集合
    {
        while (!input.eof())
        {
            string temp = handle_oneWord();
            if (find(key_set.begin(), key_set.end(), temp) != key_set.end())
            {
                ++total_num;
                if (temp == "switch")
                {
                    ++switch_num;
                    if (case_num)
                    {
                        cases.push_back(case_num);
                        case_num = 0;
                    }
                }
                else if (temp == "case")
                    ++case_num;
            }
        }
        if (case_num)
        {
            cases.push_back(case_num);
            case_num = 0;
        }
    }
    void output(int rank)
    {
        cout << "total num : " << total_num << endl;
        if (rank > 1)
        {
            cout << "switch num : " << switch_num << endl;
            cout << "case num : " ;
            for (auto it : cases)
            {
                cout << it << " ";
            }
        }
    }
};
