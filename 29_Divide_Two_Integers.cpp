/** 问题描述：
 *  给定两个整数 a 、 b ，对两个整数做相除操作，不使用乘法、除法和换算运算符。
 *  返回 a 除以 b 的值。
 *  整数除法应截断为0。
 *  假设 b 不为0。
 */

#include <iostream>

using namespace std;

int divide(int dividend, int divisor)
{
    /* 
        用异或操作得到结果的正负。
        用二进制移位操作来得结果。
        每移一位就乘2，所以multiple的值变为 1 2 4 8 16 32 ，temp的值也会变为 temp 2*temp 4*temp 。
        当a<下一个temp之后，更新a和保存multiple的值，再重新进行一轮，直到a<b。
    */

    if (!divisor || (dividend == INT_MIN && divisor == -1))
        return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;//^ 按位异或操作
    long long a = labs(dividend);
    long long b = labs(divisor);
    int res = 0;
    while (a >= b)
    {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1))
        {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        res += multiple;
    }
    return sign == 1 ? res : -res;
}

int main(int argc, char const *argv[])
{
    int dividend = 9, divisor = -3;
    cout << divide(dividend, divisor);
    return 0;
}
