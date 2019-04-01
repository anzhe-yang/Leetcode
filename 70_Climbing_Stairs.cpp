/** 问题描述：
 *  攀爬楼梯问题，到达顶部需要 n 步。
 *  每次只能攀爬 1 步或者 2 步，返回有多少种方法能够攀爬到顶部。
 *  n 是一个正整数。
 */

#include <iostream>

using namespace std;

int climbStairs(int n)
{
    /*
        动态规划算法。
        也可以理解为斐波那契数列，f(n)=f(n-1)+f(n-2)。
    */
   
    if (n == 1)
        return 1;
    
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-2] + dp[i-1];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n = 3;
    cout << climbStairs(n);
    return 0;
}
