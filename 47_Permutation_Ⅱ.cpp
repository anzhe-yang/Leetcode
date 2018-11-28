/** 问题描述：
 *  给定一组整数，可能包含重复得数，返回所有可能的不同的排列组合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permuteUnique(vector<int> nums, vector<vector<int>>& res, int i)
{
    if (i >= nums.size())
    {
        res.push_back(nums);
        return ;
    }
    for (int j = i; j < nums.size(); j++)
    {
        if (j == i || nums[j] != nums[i])
        {
            swap(nums[i], nums[j]);
            permuteUnique(nums, res, i+1);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    /*
        首先将数组排好序，为了防止出现重复的结果。
        迭代算法，i为开始的那个元素，即第一个元素，之后循环i加1。
        当前元素不等于开始元素时，说明不重复，除了第一个以外。
        每次循环前先交换第i个元素和循环开始的元素。
        当i大于数组长度时，说明本次循环结束了，该改变第一个元素之后再循环。
        可以将nums的长度定义为一个变量，增加空间，降低时间。
    */
   
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    permuteUnique(nums, res, 0);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{3, 3, 0, 3};
    vector<vector<int>> res = permuteUnique(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
