/** 问题描述：
 *  给定一个 excel 的列表头，返回相关的列数字。
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int titleToNumber(string s)
{
    /*
        利用队列保存每个字母代表的数字，并加一。
        从第一个字符开始遍历，每次将原数*26后+上当前数字。
    */

    int len = s.length();
    int res = 0;
    queue<int> num;
    for (int i = 0; i < len; i++)
    {
        num.push(s[i]-'A' + 1);
    }
    while (!num.empty())
    {
        int temp = 0;
        temp += num.front();
        res = res * 26 + temp;
        num.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "ZY";
    cout << titleToNumber(s);
    return 0;
}
