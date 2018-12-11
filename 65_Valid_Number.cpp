/** 问题描述：
 *  给定一个字符串，判断它是否可以解释为一个十进制的数字。
 *  合法数字可能有的标志标签：
 *  数字 0-9
 *  指数 e
 *  正负号 +-
 *  数值点 .
 */

#include <iostream>
#include <string>

using namespace std;

bool isNumber(string s)
{   
    /*
        DFA算法。
    */
   
    while (s[0] == ' ')
        s.erase(0, 1);
    while (s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);
    int len = s.length();
    int flag = 0;
    int state = 0;
    for (int i = 0; i < len; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            flag = 1;
            if (state <= 2)//光有正负号和数字情况
                state = 2;
            else//加了e或者.
                state = (state <= 5) ? 5 : 7;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (state == 0 || state == 3)//要么开头，要么是e的后面
                state++;
            else
                return false;
        }
        else if (s[i] == '.')
        {
            if (state <= 2)//最多具有数字加符号
                state = 6;
            else
                return false;
        }
        else if (s[i] == 'e')
        {
            if (flag && (state == 2 || state == 6 || state == 7))//flage表示必须有数字，否则不能有e，其次2代表数字加正负号
                                                                 //6代表之前那个情况再加上有.
                                                                 //7代表有.有数字有符号
                state = 3;
            else
                return false;
        }
        else
            return false;
    }
    return (state == 2 || state == 5 || (flag && state==6) || state == 7);
}

int main(int argc, char const *argv[])
{
    string s = " +9e3";
    cout << boolalpha << isNumber(s);
    return 0;
}
