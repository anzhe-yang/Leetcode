/** 问题描述：
 *  给定一个数组，其中第 i 个元素代表根据第 i 天的库存所确定的价格。
 *  设计一个算法计算其能够获得的最大利益，最多只能完成两次交易。
 *  每次交易时，如果不把当前货物卖完，则不能进行购买操作。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int maxProfit(vector<int>& prices)
{
    /*
        只循环一次的算法，不需要DP。
        循环中计算四个变量：第一次买之后的钱，第一次卖之后的钱，第二次买之后的钱，第二次卖之后的钱。
        每次都取最大值，即可找到最大利润。
    */

    // int maxBuy1 = INT_MIN, maxBuy2 = INT_MIN;//第一次第二次购买之前的钱
    // int maxProfit1 = 0, maxProfit2 = 0;//第一次卖掉货物和第二次卖掉货物后得到的利润，初始化为0
    // for (int i : prices)
    // {
    //     maxBuy1 = max(maxBuy1, 0-i);//第一次买之前，钱为0，买了第一个货物后，钱为0-prices[i]
    //     maxProfit1 = max(maxProfit1, maxBuy1+i);//第一次卖之后，由于maxBuy为负数，即利润等于maxBuy1+prices[i]
    //     maxBuy2 = max(maxBuy2, maxProfit1-i);//第二次买之前，拥有的钱，即结束第一次交易后的利润maxProfit1，买之后减去prices[i]
    //     maxProfit2 = max(maxProfit2, maxBuy2+i);//第二次卖之后，利润为买之后的钱加上prices[i]
    // }//循环一次即可找到两次交易后的最大利润
    // return maxProfit2;


    /*
        常规动态规划解法。
        第一维度：到第i天的最大利润
        第二维度：交易了k次
        第三维度：0为当前无库存，可以买，1为当前有库存，可以卖
    */

    int n = prices.size();
    int k = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, 0)));
    for (int i = 0; i <= k; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = -prices[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = j==0 ? dp[i-1][j][0] : max(dp[i-1][j][0], dp[i-1][j-1][1]+prices[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]-prices[i]);
        }
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = max(res, dp[n-1][i][0]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices);
    return 0;
}
