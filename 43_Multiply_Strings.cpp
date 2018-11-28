/** 问题描述：
 *  给定两个非负整数，表示形式为字符串。
 *  求它俩的乘积，表示为字符串。
 *  假设两个整数的长度小于 110 。
 *  不能使用任何的库或直接将输入转化为整数。
 */

#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2)
{
    /* 
        乘法手写算法，逐位相乘并加进位。
        carry代表进位。
        把每一位转化为单个数字，做乘法。
        之后找第一个不为0的，裁剪出来并返回。
    */
   
    int len1 = num1.length();
    int len2 = num2.length();
    string res(len1+len2, '0');
    for (int i = len1-1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = len2-1; j >= 0; j--)
        {
            int temp = (num1[i]-'0') * (num2[j]-'0') + (res[i+j+1]-'0') + carry;
            res[i+j+1] = temp % 10 + '0';
            carry = temp / 10;
        }
        res[i] += carry;
    }
    for (int s = 0; s < len1+len2; s++)
        if (res[s] != '0')
            return res.substr(s);

    return "0";
}

int main(int argc, char const *argv[])
{
    string num1 = "123";
    string num2 = "456";
    cout << multiply(num1, num2);
    return 0;
}
