/** 问题描述：
 *  计算并返回一个数的平方根，这个数只被允许是非负整数。
 *  返回类型是一个整数，返回的十进制数字被缩短为仅保存整数部分结果。
 */

#include <iostream>

using namespace std;

int mySqrt(int x)
{
    /*
        二分法查找。
    */

    // if (x == 0)
    //     return 0;
    // int left = 1, right = INT_MAX;
    // while (true) 
    // {
    //     int mid = left + (right - left)/2;
    //     if (mid > x/mid)
    //         right = mid - 1;
    //     else 
    //     {
    //         if (mid + 1 > x/(mid + 1))
    //             return mid;
    //         left = mid + 1;
    //     }
    // }

    /*
        res的取大或者取小的时候，res变为它与x/res之间的一半。
    */
   
    if (x < 2)
        return x;
    int res = x / 2;
    while (x < res*res || x > (res+1)*(res+1))
        res = (res + x/res) / 2;
    return res;
}

int main(int argc, char const *argv[])
{
    int x = 2147395599;
    cout << mySqrt(x);
    return 0;
}
