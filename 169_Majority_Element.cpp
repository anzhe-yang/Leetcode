/** 问题描述：
 *  给定一个数组，找到出现次数超过一半的数字。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums)
{
    /*
        先排序，后找中值。
    */
   
    // if (nums.empty())
    //     return 0;
    // int len = nums.size();
    // sort(nums.begin(), nums.end());
    // return nums[len/2-1];

    /*
        遍历整个数组，建议一个计数变量。
        当第i个值与res相同，则计数加1，否则计数减1。
        当计数值为0时，重新设定当前值为res，并开始计数。
        因为次数超过一半的数字肯定能保留下来，所以最终的res就是结果。
    */
    int len = nums.size();
    int count = 1;
    int res = nums[0];
    for (int i = 1; i < len; i++)
    {
        if (count == 0)
        {
            count++;
            res = nums[i];
        }
        else if (nums[i] == res)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 1, 1, 2, 3, 3};
    cout << majorityElement(nums);
    return 0;
}
