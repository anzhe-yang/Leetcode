/** 问题描述：
 *  给定一组整数数组和一个目标整数，找出数组中四个整数之和为目标整数的不同的唯一组合。
 *  结果组合中不能包含重复的四元组合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > fourSum(vector<int>& nums, int target)
{
    /*
        首先排序整个数组，若长度为4则直接返回。
        用i，j，lo，hi代表四个位置。
        i：若每个位置的前后数值相等，则往下走，同时若大于目标则直接停止，若加上最大的几个数字还小于目标，则往下走。
        j：与i一致。
        lo：比j大1。
        hi：代表数组最后一个数值，若小于最后所要求的那个数，则使lo加一，同时自己循环，直到等于lo，若hi与之后的数值相等，则往下走。
    */

    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector< vector<int> > quadruplets;
    if (len < 4)
        return quadruplets;

    for (int i = 0; i < len-3; i++)
    {
        if (i>0 && nums[i-1]==nums[i])
            continue;
        if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target)
            break;
        if (nums[i]+nums[len-3]+nums[len-2]+nums[len-1] < target)
            continue;
        for (int j = i+1; j < len-2; j++)
        {
            if (j>i+1 && nums[j-1]==nums[j])
                continue;
            if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target)
                break;
            if (nums[i]+nums[j]+nums[len-2]+nums[len-1] < target)
                continue;
            int lo = j + 1;
            for (int hi = len-1; hi > lo; hi--)
            {
                if (hi<len-1 && nums[hi]==nums[hi+1])
                    continue;
                while (nums[lo] < (target-(nums[i]+nums[j]+nums[hi])))
                    lo++;
                if (lo<hi && (nums[i]+nums[j]+nums[lo]+nums[hi]==target))
                    quadruplets.push_back({nums[i], nums[j], nums[lo], nums[hi]});
            }
        }
    }
    return quadruplets;
}

int main(int argc, char const *argv[])
{
    int a[] = {0, 0, 0, 0};
    vector<int> nums(a, a+4);
    int target = 0;
    vector< vector<int> > res = fourSum(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
