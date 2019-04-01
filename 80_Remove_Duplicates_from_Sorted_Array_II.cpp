/** 问题描述：
 *  给定一个排好序的整数数组，去除重复两次以上的数字，并返回修改后的数组长度。
 *  不允许使用额外的数组空间，只允许 O(1) 的额外内存。
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    /*
        设置一个位置变量i，遍历整个数组。
        前两个元素直接不变，从第三个元素开始。
        如果当前元素大于前两个元素，则不变，否则去掉。
        最终长度即为位置变量i。
    */

    int i = 0;
    for (auto s : nums)
    {
        if (i < 2 || s > nums[i-2])
        {
            nums[i++] = s;
        }
    }
    return i;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 1, 1};
    cout << removeDuplicates(nums);
    return 0;
}
