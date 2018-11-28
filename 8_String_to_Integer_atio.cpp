/** 问题描述：
 *  将一个字符串转化为一个整数。
 *  函数首先抛弃到空字符，之后从下个字符开始，若出现 ‘-’ ‘+’ 符号则应被认为是数字正负符号。
 *  除了数字以外的所有字符都被抛弃。
 *  若第一个非空字符序列不是合法整型数字，或没有正规序列存在，不做任何处理。
 *  若没有正规转换发生，返回 0 。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int myAtoi(string str)
{
    /*
        先找到第一个不是空的字符，从这开始。
        判断第一个是否为正负符号，之后判断是否是数字。
        超出范围则返回边界值。
    */
   
    long result = 0;
    int sign = 1;
    int len = str.length();
    int space = str.find_first_not_of(' ');
    if (space >= len)
        return 0;
    for (int i = space; i < len; i++)
    {
        if (str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '-')? -1 : 1;
        while (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i++] - '0');
            if (result * sign >= INT32_MAX) return INT32_MAX;
            if (result * sign <= INT32_MIN) return INT32_MIN;
        }
        return (result * sign);
    }
}

int main(int argc, char const *argv[])
{
    string str = "-91283472332";
    int atoi = myAtoi(str);
    cout << atoi;
    return 0;
}
