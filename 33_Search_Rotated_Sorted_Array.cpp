/** 问题描述：
 *  假设一个按升序排列的数组在事先未知的某个位置旋转。
 *  如0，1，2，4，5，6，7变为4，5，6，7，0，1，2。
 *  给定一个要搜索的目标值，如果在数组中找到了则返回其索引值，否则返回-1。
 *  假设数组中不存在重复的元素。
 *  算法的运行复杂度必须为 O(logN) 的顺序。
 */

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    /*
        由于数组之前是升序，被打乱。
        若第一个数大于目标，则目标数在后面，从后开始找。
        否则从前开始找。
    */

    // if (nums.empty())
    //     return -1;

    // int len = nums.size();
    // if (nums[0] > target)
    // {
    //     for (int i = len-1; i > 0; i--)
    //     {
    //         if (nums[i] == target)
    //             return i;
    //     }
    //     return -1;
    // }
    // else if (nums[0] == target)
    //     return 0;
    // else if (nums[0] < target)
    // {
    //     for (int i = 1; i < len; i++)
    //     {
    //         if (nums[i] == target)
    //             return i;
    //     }
    //     return -1;
    // }

    /*
        二分法查找。
    */

    int len = nums.size();
    int lo = 0, hi = len-1;
    while (lo < hi)
    {
            int mid = (lo+hi) / 2;
            if (nums[mid] > nums[hi])
                lo = mid+1;
            else
                hi = mid;
    }//最终lo和hi都指向数组中最小那个数的索引位置,同时也是旋转的那个位置
    int rotation = lo;
    lo = 0, hi = len-1;
    while (lo <= hi)
    {
        int mid = (lo+hi) / 2;
        int realmid = (mid + rotation) % len;
        if (nums[realmid] == target)
            return realmid;
        if (nums[realmid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }//二分搜索，并加上旋转
    return -1;
}

int main(int argc, char const *argv[])
{
    int num[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums(num, num+7);
    int target = 0;
    cout << search(nums, target);
    return 0;
}
