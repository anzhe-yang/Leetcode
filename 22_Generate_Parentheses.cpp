/** 问题描述：
 *  给定 n 对括号，编写一个函数来生成所有的格式正确的括号组合。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> res;
void insert(string, int, int);
vector<string> generateParenthesis(int n)
{
    /*
        利用insert函数做递归操作。
        若左括号的数量小于n，则s加上一个左括号。
        若右括号的数量小于左括号，则s加上一个右括号。
    */

    if (n <= 0)
        return res;
    insert("", n, 0);
    return res;
}

void insert(string s, int left_need, int right_need)
{
    if (left_need == 0 && right_need == 0)
    {
        res.push_back(s);
        cout << s << endl;
        return;
    }
    if (left_need > 0)
        insert(s+"(", left_need-1, right_need+1);
    if (right_need > 0)
        insert(s+")", left_need, right_need-1);
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
