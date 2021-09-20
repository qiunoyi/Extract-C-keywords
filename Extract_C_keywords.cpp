#include "if_else.h"
#include "input.h"
int main()
{
    cout << "请输入您需要的关键字查找等级" << endl;
    int rank = 1;
    cin >> rank;
    if (rank > 4 || rank < 1)
    {
        cout << "请输入[1,4]的数字" << endl;
    }
    Input_KeyWords key("key.txt");
    auto key_set = key.read();
    cout << "请输入您要提取的cpp文件路径" << endl;
    string address;
    cin >> address;
    Count code(address);
    code.count_total(key_set);
    code.output(rank);
    if (rank >= 3)
    {
        ifstream input2(address);
        if_else(input2);
        cout << "if-else num: " << if_else_num << endl;
        if (rank == 4)
            cout << "if-elseif-else num: " << if_else_if_else_num << endl;
    }
}