/** 问题描述：
 *  给定一个排好序的数组和一个目标值，如果在数组中找到了目标值则返回其索引。
 *  如果没有找到，返回目标值应该按其顺序插入的位置。
 */

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{   
    /*
        二分法查找。
    */
   
    int len = nums.size();
    int lo = 0, hi = len-1;
    while (lo <= hi)
    {
        int mid = lo + (hi-lo) / 2;
         if (nums[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return lo;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 3};
    int target = 3;
    cout << searchInsert(nums, target);
    return 0;
}
