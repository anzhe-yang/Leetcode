/** 问题描述：
 *  假设一个升序排列的数组从中间某个点进行了翻转。
 *  找到翻转后最小的元素。
 *  假设数组中可能包含重复元素。
 */

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums)
{
    /*
        二分法查找。
        如果出现相同的元素，将边界向前回推。
    */
   
    int len = nums.size();
    int left = 0, right = len-1;
    int mid = 0;
    while (left < right)
    {
        //举个例子，for (int i = 0; i < INT_MAX; i++)
        //这时如果两个数之和大于INT_MAX就会溢出，如果采用下面这种方法就不会产生溢出
        mid = left + ((right-left) >> 1);//防止溢出
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right--;
    }
    return nums[left];
}

int main(int argc, char const *argv[])
{
    vector<int> nums{5, 2, 2, 3, 4};
    cout << findMin(nums);
    return 0;
}
