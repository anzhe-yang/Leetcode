/** 问题描述：
 *  如果某个元素大于它周围的元素，则称为山顶元素。
 *  给定一个数组，数组中相邻两个元素不相等，找到其中的山顶元素并返回位置索引。
 *  数组可能包含多个山顶元素，可以任意返回某一个。
 *  可以假设数组的 -1 索引和 n 索引的值为负无穷。
 *  算法复杂度为 O(logN) 。
 */

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
    /*
        二分法。
        比较当前mid值和下一个值。
        如果小于它，则说明山顶值在右方，否则在左方。
    */
   
    int len = nums.size();
    int left = 0, right = len-1;
    int mid = 0;
    while (left < right)
    {
        mid = left + ((right-left) >> 1);
        if (nums[mid] < nums[mid+1])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{};
    cout << findPeakElement(nums);
    return 0;
}
