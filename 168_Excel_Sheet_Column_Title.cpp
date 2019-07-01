/** 问题描述：
 *  给定一个正整数，返回 excel 相关的列表头。
 *  1 A
 *  2 B
 *  26 Z
 *  27 AA
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string convertToTitle(int n)
{
    /*
        利用一个栈变量保存每次除下来的余数。
        计算余数之前要先将n-1，因为要将1-26视为0-25。
        每次得到余数后，更新n。
        最后从后往前，加上每一个余数所得到的字符值，构成结果。
    */
   
    string res = "";
    stack<int> remainder;
    while (n > 0)
    {
        n -= 1;
        remainder.push(n % 26);
        n /= 26;
    }
    while (!remainder.empty())
    {
        res += 'A' + remainder.top();
        remainder.pop();
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 701;
    cout << convertToTitle(n);
    return 0;
}
