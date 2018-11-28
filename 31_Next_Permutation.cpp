/** 问题描述：
 *  实现获取下一个排列的函数，算法需要将给定的数字序列重新排列成字典序中下一个更大的排列。
 *  如果不存在下一个更大的排列，则将数字重新排列成最小的排列，即升序序列。
 *  必须在输入的基础上修改，只允许使用额外的常数空间。
 *  例子：
 *  1,2,3 -> 1,3,2
 *  3,2,1 -> 1,2,3
 *  1,1,5 -> 1,5,1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    /*
        从数组中以逆序找出顺序不对的那个数，记为l-1和l。
        如果l是第一个数，则重新排列成最小的排序。
        否则找出从l-1以后找出最接近第l-1的数，交换它们，并重新排序l-1之后的数。
    */
   
    int len = nums.size();
    int l = len-1;
    for (; l > 0; l--)
    {
        if (nums[l] > nums[l-1])
            break;
    }
    if (l == 0)
        reverse(nums.begin(), nums.end());
    else
    {
        int k = 0;
        for (k = len-1; k > l-1; k--)
        {
            if (nums[k] > nums[l-1])
                break;
        }
        swap(nums[l-1], nums[k]);
        reverse(nums.begin()+l, nums.end());
    }
}

int main(int argc, char const *argv[])
{
    int num[] = {5,5,4,1,3,2};
    vector<int> nums(num, num+6);
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}
