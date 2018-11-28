/** 问题描述：
 *  给定一个 32bit 的有符号整数，反转这个整数。
 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int reverse(int x)
{
    /*
        按位反转。
    */
   
    int res;
    while (x != 0)
    {
        int each_num = x % 10;
        x /= 10;
        res = res * 10 + each_num;
    }
    if (res > INT32_MAX/10) return 0;
    if (res < INT32_MIN/10) return 0;
    return res;
}

int main(int argc, char const *argv[])
{
    int x = -123;
    int revx = reverse(x);
    cout << revx;
    return 0;
}
