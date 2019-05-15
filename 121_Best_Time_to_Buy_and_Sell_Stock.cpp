/** 问题描述：
 *  给定一个数组，其中第 i 个元素代表根据第 i 天的库存所确定的价格。
 *  每次只允许完成一次交易，即只能买或者只能卖。
 *  设计一个算法找到其最大的收益。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices)
{
    /*
        笨方法。两个循环遍历，找差值最大。
    */

    // int n = prices.size();
    // int res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (prices[i] < prices[j])
    //         {
    //             int tmp = prices[j] - prices[i];
    //             res = max(res, tmp);
    //         }
    //     }
    // }
    // return res;

    /*
        机智方法。
        一次循环遍历。
        找价格最小的值，找价格最大的值。
        且最大值元素位置必须在最小值元素位置的后面。
        找最大值即可转换为找差值最大的元素。
    */
   
    int n = prices.size();
    int minPrice = INT_MAX;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > res)
            res = prices[i] - minPrice;
    }
    return res;

}

int main(int argc, char const *argv[])
{
    vector<int> prices{1, 2};
    cout << maxProfit(prices);
    return 0;
}
