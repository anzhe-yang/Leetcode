/** 问题描述：
 *  给定一组非负数整数数组，最初的位置在数组的第一个索引处。
 *  数组中每个元素表示该位置的最大跳转长度。
 *  目标是以最小跳跃次数到达最后一个索引。
 *  假设每个数组都是可行的。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums)
{
    /*
        curMax代表了当前达到的最远索引，furMax代表了以当前方法能达到的最远索引。
        如果furMax超过了索引长度，则说明此方法可行，返回res+1。
        否则说明当前索引还不行，res的索引就加1，当前最远索引值更新。
        如果最后还不行，说明此数组不可行。
    */
   
    int len = nums.size();
    if (len < 2)
        return 0;
    
    int res = 0, curMax = 0, i = 0;
    while (i <= curMax)
    {
        int furMax = curMax;
        for (; i <= curMax; i++)
        {
            furMax = max(furMax, nums[i]+i);
            if (furMax >= len-1)
                return res+1;
        }
        res++;
        curMax = furMax;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 3, 1, 1, 4};
    cout << jump(nums);
    return 0;
}
