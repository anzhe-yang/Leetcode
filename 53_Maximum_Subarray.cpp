/** 问题描述：
 *  给定一组整数数组，找到其中和最大的相连子数组，返回最大子数组的和。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    /*
        动态规划算法，找到子问题的形式。
        子问题形式：maxSubArray(nums, i) = maxSubArray(nums, i-1) > 0 ? maxSubArray(nums, i-1) : 0+nums[i]。
        其中res设置为dp数组中最大的，并返回其值。
    */

    // int len = nums.size();
    // int dp[len];
    // dp[0] = nums[0];
    // int res = dp[0];

    // for (int i = 1; i < len; i++)
    // {
    //     dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
    //     res = max(res, dp[i]);
    // }

    // return res;

    /*
        temp设置为当前子数组的和。
        res设置为当前的最大和。
        如果在下一个循环中，temp小于0，则清零。
    */

    int len = nums.size();
    int res = nums[0];
    int temp = 0;
    
    for (int i = 0; i < len; i++)
    {
        temp += nums[i];
        res = max(res, temp);
        temp = max(temp, 0);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int num[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums(num, num+9);
    cout << maxSubArray(nums);
    return 0;
}
