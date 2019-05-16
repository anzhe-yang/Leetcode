/** 问题描述：
 *  沿着一个环形路有 N 个加油站，在第 i 个加油站有 gas[i] 升汽油。
 *  你有一个不限制汽油容量的车，它从第 i 个加油站到第 i+1 个加油站需要花费 cost[i] 升汽油。
 *  你起始于某一个加油站，并且油箱为空。
 *  如果你能沿着顺时针经过所有加油站一次，返回起始加油站的索引，否则返回 -1 。
 *  解决方案只有一种，gas 和 cost 数组都非空，且拥有相同的长度。
 *  每个元素都为非负整数。
 */

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    /*
        start表示从这个点出发，curGas代表当前剩余油量。
        通过len和while(len<n)和if(i==n)表示从特定位置开始循环整个数组。
        如果curGas-cost[i]小于0，则此路不通，起始点+1。
        如果所有加油站都走完了，即len=n，且剩余油量还大于等于0，则说明此路通，返回start。
    */

    // if (gas.empty() || cost.empty())
    //     return 0;
    // int n = gas.size();
    // int start = 0;
    // while (start < n)
    // {
    //     int curGas = 0;
    //     int i = start;
    //     int len = 0;
    //     while (len < n)
    //     {
    //         if (i == n)
    //             i = 0;
    //         curGas += gas[i];
    //         if (curGas - cost[i] >= 0)
    //         {
    //             curGas -= cost[i];
    //         }
    //         else
    //         {
    //             start++;
    //             break;
    //         }
    //         i++;
    //         len++;
    //     }
    //     if (len == n && curGas >= 0)
    //     {
    //         return start;
    //     }
    // }
    // return -1;

    /*
        当前路径的整体油量，即将每次的剩余油量都加起来，组成totalGas，如果加上最后一个curGas大于0，则此路通。
        如果从加油站a无法到达加油站b，则在a和b的加油站之间的所有加油站都不能作为起点，所以都不考虑，将start=i+1。
    */
   
    int start = 0, curGas = 0, totalGas = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        curGas = curGas + gas[i] - cost[i];
        if (curGas < 0)
        {
            start = i + 1;
            totalGas += curGas;
            curGas = 0;
        }
    }
    return (totalGas+curGas>=0) ? start : -1;
}

int main(int argc, char const *argv[])
{
    vector<int> gas{3, 3, 4};
    vector<int> cost{3, 4, 4};
    cout << canCompleteCircuit(gas, cost);
    return 0;
}
