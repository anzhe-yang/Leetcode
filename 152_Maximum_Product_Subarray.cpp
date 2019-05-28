/** 问题描述：
 *  给定一个整数数组，找到具有最大乘积的连续子数组。
 *  子数组至少包含一个数字。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums)
{
    /*
        定义两个变量，rmax和rmin，保存当前位置时的最小值和最大值。
        因为如果当前值是负数，会使得小数变大，大数变小。
        所以负数时将rmax和rmin交换。
        如果前面所得值是负数，则有可能乘以一个负数后会变得更大，所以要考虑最小值。
        每次循环都将rmax和rmin更新，最后通过比较rmax和res得到最大值。
    */
   
    int len = nums.size();
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[0];

    int res = nums[0];
    int rmax = res, rmin = res;
    for (int i = 1; i < len; i++)
    {
        if (nums[i] < 0)
        {
            int temp = rmax;
            rmax = rmin;
            rmin = temp;
        }

        rmax = max(nums[i], nums[i]*rmax);
        rmin = min(nums[i], nums[i]*rmin);
        res = max(res, rmax);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{0, 2, -2};
    cout << maxProduct(nums);
    return 0;
}
