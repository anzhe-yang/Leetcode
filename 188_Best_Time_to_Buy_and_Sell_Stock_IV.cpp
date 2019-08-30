/** 问题描述：
 *  给定一个数组，其中第 i 个元素代表当前货物在第 i 天的价格。
 *  设计一个算法去找到能获得最大利益的交易方法，最多只能完成 k 次交易。
 *  且同一天不能完成多次交易。
 */

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    /*
        动态规划。
        当k大于天数的一半时，说明每天都交易一次也可以。
        定义一个二维矩阵，横坐标代表交易i次得到的利润，纵坐标代表前i天的总利润。
        dp[i][j]代表在前j天中，最多交易i次得到的最大利润。
        如果当前价格最高，想卖出，前提是先买入，则利润为prices[j]-prices[t]，在第t天买入，第j天卖出。
        则这个最大利润即为prices[j]-prices[t]+dp[j-1][t-1]，也就是加上交易次数少一次，第t天前的最大利润。
        t:0->j-1                max(prices[j]-prices[t]+dp[i-1][t-1])
        prices[j] + t:0->j-1    max(dp[i-1][t-1]-prices[t])
        cur_max为max(dp[i-1][t-1]-prices[t])，找到以当前j为基准的最大利润，然后加上prices[j]就为当前最大利润。
        然后与前一天的最大利润比较，取最大值作为当前天的最大利润。
    */

    int res = 0;
    if (prices.size() < 2) {
        return res;
    } else if (k > prices.size()/2) {
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i-1]);
        }
        return res;
    }

    vector<vector<int>> profits(k+1, vector<int>(prices.size()));
    for (int i = 1; i <= k; i++) {
        int cur_max = -prices[0];
        for (int j = 1; j < prices.size(); j++) {
            profits[i][j] = max(profits[i][j-1], prices[j]+cur_max);
            cur_max = max(cur_max, profits[i-1][j-1] - prices[j]);
        }
    }
    return profits[k][prices.size()-1];
}

int main(int argc, char const *argv[])
{
    vector<int> prices{1, 7, 4, 2};
    int k = 2;
    cout << maxProfit(k, prices);
    return 0;
}
