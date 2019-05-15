/** 问题描述：
 *  给定一组整数数组，找出其中三个整数相加为零的不同的组合。
 *  结果不能包含重复的组合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int>& nums)
{
    /*  
        先排序数组，后两个数按照从两边到中间的策略开始找，当满足条件则加入数组。
    */

    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector< vector<int> > res;
    for (int i = 0; i < len-1; i++)
    {
        if (i>0 && nums[i-1]==nums[i])
            continue;
        int lo = i + 1;
        for (int hi = len-1; hi > lo; hi--)
        {
            if (hi<len-1 && nums[hi]==nums[hi+1])
                continue;
            while (nums[lo] < -(nums[i]+nums[hi]))
                lo++;
            if (lo<hi && (nums[i]+nums[lo]+nums[hi] == 0))
            {
                res.push_back({nums[i], nums[lo], nums[hi]});
            }
        }
    }
    return res;

    /*
        先排序数组，将vector转化为int类数组形式，可以使用find函数。
        固定前两个数，用find函数找第三个数，加入到res数组中。
    */
   
    // sort(nums.begin(), nums.end());
    // int len = nums.size();
    // vector< vector<int> > res;
    // int temp[len];
    // for (int i = 0; i < len; i++)
    //     temp[i] = nums[i];

    // for (int a = 0; a < len-2; a++)
    // {
    //     for (int b = a+1; b < len-1; b++)
    //     {
    //         if (temp[a] != temp[a-1])
    //         {
    //             int tp = -(temp[a]+temp[b]);
    //             int *l = find(temp+b, temp+len, tp);
    //             if (l != temp+len)
    //                 res.push_back({temp[a], temp[b], (*l)});
    //         }
    //     }
    // }
    // return res;
}

int main(int argc, char const *argv[])
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(a, a+6);
    vector< vector<int> > arrays = threeSum(nums);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << arrays[i][j] << " ";
        cout << endl;
    }
    return 0;
}
