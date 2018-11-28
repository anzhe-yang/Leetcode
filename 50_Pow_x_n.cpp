/** 问题描述：
 *  计算 x 的 n 次方结果。
 *  假设 x 在-100.0到100.0之间。
 *  n 是一个32bit的有符号数。
 */

#include <iostream>
#include <iomanip>

using namespace std;

double myPow(double x, int n)
{
    /*
        用递归方法算次方，每次n除以2。
        最后判断n是否为单数，解决各类问题。
    */

    if (n == 0)
        return 1;

    double temp = myPow(x, n/2);
    if (n % 2 == 0)
        return temp * temp;
    else if (n > 0)
        return temp * temp * x;
    else
        return (temp*temp) / (x*1.0);
}

int main(int argc, char const *argv[])
{
    double x = 2.00000;
    int n = -2;
    cout << setiosflags(ios::fixed) << setprecision(5) << myPow(x, n);
    return 0;
}
