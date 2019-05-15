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

    int maxBuy1 = INT_MIN, maxBuy2 = INT_MIN;//第一次第二次购买之前的钱
    int maxProfit1 = 0, maxProfit2 = 0;//第一次卖掉货物和第二次卖掉货物后得到的利润，初始化为0
    for (int i : prices)
    {
        maxBuy1 = max(maxBuy1, 0-i);//第一次买之前，钱为0，买了第一个货物后，钱为0-prices[i]
        maxProfit1 = max(maxProfit1, maxBuy1+i);//第一次卖之后，由于maxBuy为负数，即利润等于maxBuy1+prices[i]
        maxBuy2 = max(maxBuy2, maxProfit1-i);//第二次买之前，拥有的钱，即结束第一次交易后的利润maxProfit1，买之后减去prices[i]
        maxProfit2 = max(maxProfit2, maxBuy2+i);//第二次卖之后，利润为买之后的钱加上prices[i]
    }//循环一次即可找到两次交易后的最大利润
    return maxProfit2;
}

int main(int argc, char const *argv[])
{
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(prices);
    return 0;
}
