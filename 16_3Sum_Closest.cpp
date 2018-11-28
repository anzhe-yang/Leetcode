/** 问题描述：
 *  给定一组整数数组和一个整数目标，从数组中找出三个整数，使其之和最接近于目标整数。
 *  返回这三个整数的和。
 *  假设每组数组只有一种解。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    /*  
        先排序整个数组，i，j，k代表三个数。
        j比i大1，k代表最后一个数字，两头往中间走，找出等于目标数值的组合。
        若不等于，找出目标之差gap最小的组合。
        组合之和大，k就减小，反之j增大。
    */
   
    int len = nums.size();
    int gap = INT_MAX;
    int closest = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len-2; i++)
    {
        int j = i + 1;
        int k = len - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)  
                return sum;
            int diff = abs(sum - target);
            if (gap > diff)
            {
                gap = diff;
                closest = sum;
            }
            if (sum > target)
                k--;
            else
                j++;
        }
    }
    return closest;
}

int main(int argc, char const *argv[])
{
    int a[] = {0, 2, 1, -3};
    vector<int> nums(a, a+4);
    int target = 1;
    cout << threeSumClosest(nums, target);
    return 0;
}
