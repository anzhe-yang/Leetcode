/** 问题描述：
 *  给定一个按升序排好的数组，按未知的某个轴进行旋转操作。
 *  给定一个目标值，寻找它是否存在于此数组。
 */

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
    /*
        二分法。
        第一种情况判断目标值在哪个范围。
        第二种情况判断左边范围。
        第三种情况判断右边范围。
    */
   
    if (nums.empty())
        return false;
    int len = nums.size();
    int left = 0, right = len-1, mid = 0;
    while (left <= right)
    {
        mid = (left+right) / 2;
        if (nums[mid] == target)
            return true;
        
        if (nums[left]==nums[mid] && nums[right]==nums[mid])
        {
            left++;
            right--;
        }

        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] < target && nums[right] >= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1};
    int target = 1;
    cout << boolalpha << search(nums, target);
    return 0;
}
