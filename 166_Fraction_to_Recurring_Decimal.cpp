/** 问题描述：
 *  给定两个整数表示一个分数的分子和分母，返回分数的字符串形式。
 *  如果小数部分是循环的，用括号将循环部分包含起来。
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    /*
        通过异或判断两个数是否符号不同。
        labs返回这个数的绝对值并返回long类型。
        先判断是否能整除，如果可以，直接返回。
        如果不能整除，说明有小数。
        通过一个map变量保存余数和一个量值，量值只需能判断出当前余数是否出现过。
        通过将余数*10，并除以分母，压入res。
        当前余数如果之前出现过，说明发生循环，在循环体前加入(。
     */
    if (denominator == 0)
    {
        return "";
    }
    if (numerator == 0)
    {
        return "0";
    }
    string res = "";
    //符号部分
    if (numerator < 0 ^ denominator < 0)
    {
        res += '-';
    }
    //整数部分
    res += to_string(labs(numerator) / labs(denominator));
    if (numerator % denominator == 0)
    {
        return res;
    }
    //小数部分
    res += '.';
    long remainder = labs(numerator) % labs(denominator);
    unordered_map<long, int> map;
    while (remainder)
    {
        if (map.count(remainder) > 0)//只要当前余数在之前出现过，证明发生循环
        {
            // res += '(';
            // res += map[remainder];
            res.insert(map[remainder], 1, '(');//在循环部分的最前面，也就是之前保存过的map[remainder]前一位加一个(
            res += ')';
            break;
        }
        map[remainder] = res.size();

        remainder *= 10;
        res += to_string(labs(remainder) / labs(denominator));
        remainder %= denominator;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int numerator = -1, denominator = -2147483648;
    cout << fractionToDecimal(numerator, denominator);
    return 0;
}
