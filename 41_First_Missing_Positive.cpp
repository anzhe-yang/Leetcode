/** 问题描述：
 *  给定一个没有排序的数组，找到除数组中所有数外的最小的正数。
 *  算法时间复杂度为 O(n) ，空间复杂度为 O(1) 。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    /*
        将每个正数放到它应该在的位置。
        如5应该放在数组中第4个位置上，即nums[i]-1。
        到最后都是排列好的数组，如果第一个位置不是正确的，则返回当前位置+1。
        否则顺序都是正确的，返回数组长度+1。
    */
   
    for (int i = 0; i < nums.size(); i++)
    {
        while (nums[i]>0 && nums[i]<nums.size() && nums[nums[i]-1]!=nums[i])
            swap(nums[i], nums[nums[i]-1]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i+1)
            return i+1;
    }
    return nums.size()+1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{7,8,9};
    cout << firstMissingPositive(nums);
    return 0;
}
