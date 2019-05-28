/** 问题描述：
 *  假设一个升序排列的数组从中间某个点进行了翻转。
 *  找到翻转后最小的元素。
 *  假设数组中没有重复元素。
 */

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    /*
        二分法查找。
    */
   
    int len = nums.size();
    int left = 0, right = len-1;
    while (left < right)
    {
        if (nums[left] < nums[right])
            return nums[left];
        
        int mid = (left + right) >> 1;
        if (nums[mid] >= nums[left])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 1};
    cout << findMin(nums);
    return 0;
}
