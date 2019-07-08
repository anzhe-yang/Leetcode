/** 问题描述：
 *  给定一个整数，返回其阶乘结果末尾中 0 的个数。
 *  算法时间复杂度为 log(N) 。
 */

#include <iostream>

using namespace std;

int trailingZeroes(int n)
{
    /*
        计算阶乘末尾零的个数，也就是计算结果为10的个数。
        10只能从2和5相乘得到，2是肯定有的，那么需要计算5的个数。
        而25有5个5，125有25个5，也就是5个5个5，也就是有除了25个因数5外，还有额外的5个因数5，所以这个算法应该这么写：
        5^1 : 4617 / 5 = 923.xx -> 保存923个因数5
        5^2 : 4617 / 25 = 184.xx -> 保存184个额外的因数5
        ...
        直到除的结果为0时停止，保存上述因数5的总和。
    */
    int res = 0;
    for (long long i = 5; n/i > 0; i*=5)
    {
        res += (n/i);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 15;
    cout << trailingZeroes(n);
    return 0;
}
