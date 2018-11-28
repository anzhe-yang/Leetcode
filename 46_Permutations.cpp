/** 问题描述：
 *  给定一组不同的整数，返回所有可能的排列组合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int>& nums, vector<vector<int>>& res, int i)
{
    if (i >= nums.size())
    {
        res.push_back(nums);
        return ;
    }
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        permute(nums, res, i+1);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    /*
        迭代算法，i为开始的那个元素，即第一个元素，之后循环i加1。
        每次循环前先交换第i个元素和循环开始的元素，迭代之后再交换一次，即初始化一次。
        当i大于数组长度时，说明本次循环结束了，该改变第一个元素之后再循环。
    */
   
    vector<vector<int>> res;
    permute(nums, res, 0);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
