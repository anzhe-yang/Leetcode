/** 问题描述：
 *  给定两组二进制字符串，返回它们的和。
 *  假设输入的都是非空字符串，仅包含 0 或 1。
 */

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
    /*
        傻瓜法。
    */

    // int lena = a.length();
    // int lenb = b.length();
    // string res = "";
    // int x = lena - 1;
    // int y = lenb - 1;
    // int sign = 0;
    // while (x >= 0 && y >= 0)
    // {
    //     if (a[x] == '1' && b[y] == '1')
    //     {
    //         if (sign == 0)
    //         {
    //             res += '0';
    //             sign = 1;
    //         }
    //         else
    //         {
    //             res += '1';
    //             sign = 1;
    //         }
    //     }
    //     else if (a[x] == '0' && b[y] == '0')
    //     {
    //         if (sign == 0)
    //         {
    //             res += '0';
    //         }
    //         else
    //         {
    //             res += '1';
    //             sign = 0;
    //         }
    //     }
    //     else
    //     {
    //         if (sign == 0)
    //         {
    //             res += '1';
    //         }
    //         else
    //         {
    //             res += '0';
    //         }
    //     }
    //     x--;
    //     y--;
    // }

    // if (x < 0)
    // {
    //     if (y >= 0)
    //     {
    //         if (sign == 0)
    //         {
    //             while (y >= 0)
    //             {
    //                 res += b[y];
    //                 y--;
    //             }
    //         }
    //         else
    //         {
    //             while (y >= 0)
    //             {
    //                 if (sign == 1)
    //                 {
    //                     if (b[y] == '0')
    //                     {
    //                         res += '1';
    //                         sign = 0;
    //                     }
    //                     else
    //                     {
    //                         res += '0';
    //                     }
    //                 }
    //                 else
    //                 {
    //                     res += b[y];
    //                 }
    //                 y--;
    //             }
    //         }
    //     }
    // }
    // if (y < 0)
    // {
    //     if (x >= 0)
    //     {
    //         if (sign == 0)
    //         {
    //             while (x >= 0)
    //             {
    //                 res += a[x];
    //                 x--;
    //             }
    //         }
    //         else
    //         {
    //             while (x >= 0)
    //             {
    //                 if (sign == 1)
    //                 {
    //                     if (a[x] == '0')
    //                     {
    //                         res += '1';
    //                         sign = 0;
    //                     }
    //                     else
    //                     {
    //                         res += '0';
    //                     }
    //                 }
    //                 else
    //                 {
    //                     res += a[x];
    //                 }
    //                 x--;
    //             }
    //         }
    //     }
    // }
    // if (sign == 1)
    // {
    //     res += '1';
    // }
    // int len = res.length();
    // string result = "";
    // for (int i = len-1; i >= 0; i--)
    // {
    //     result += res[i];
    // }
    // return result;

    /*
        carry表示进位。
        sign表示计算完当前位置元素后进位0次还是1次还是2次。
        sign对2除余代表了计算后的元素。
        sign除以2表示了计算所产生的进位。
    */
   
    int n1 = a.length() - 1;
    int n2 = b.length() - 1;
    string res = "";
    int carry = 0;
    while (n1 >= 0 || n2 >= 0)
    {
        int sign = carry;
        if (n1 >= 0)
        {
            sign += a[n1] - '0';
        }
        if (n2 >= 0)
        {
            sign += b[n2] = '0';
        }
        res += to_string(sign % 2);
        carry = sign / 2;
        n1--;
        n2--;
    }
    if (carry == 1)
        res += '1';
    
    int temp = res.length();
    for (int i = 0; i < temp/2; i++)
    {
        swap(res[i], res[temp-1-i]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string a = "1100";
    string b = "101";
    cout << addBinary(a, b);
    return 0;
}
