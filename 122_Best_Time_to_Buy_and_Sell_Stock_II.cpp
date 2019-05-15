/** 问题描述：
 *  给定一个数组，其中第 i 个元素代表根据第 i 天的库存所确定的价格。
 *  设计一个算法计算其能够获得的最大利益，可以完成多次交易。
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
        只要能获得利润，就买之。
    */
   
    int res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i-1])
        {
            res += prices[i] - prices[i-1];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}
