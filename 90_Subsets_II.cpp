/** 问题描述：
 *  给定一个可能包含重复数字的整数集合，返回所有可能的子集合。
 *  结果不能包含重复的子集合。
 */

#include <iostream>
#include <vector>

using namespace std;

// void subsetsWithDup(vector<int> nums, vector<vector<int>>& res, vector<int>& temp, int p)
// {
//     res.push_back(temp);
//     for (int i = p; i < nums.size(); i++)
//     {
//         if (i == p || nums[i] != nums[i-1])//取不重复的数字，重复则往下走，第一个数字除外
//         {
//             temp.push_back(nums[i]);
//             subsetsWithDup(nums, res, temp, i+1);
//             temp.pop_back();
//         }
//     }
// }

vector< vector<int> > subsetsWithDup(vector<int>& nums)
{
    /*
        回溯法。
        首先要将数组排序，否则子函数的if判断就会失效。
        之后定义子函数，当i是第一个位置或者第i个数字不等于前一个数字时，调用循环函数。
    */

    // sort(nums.begin(), nums.end());
    // vector<vector<int>> res;
    // vector<int> temp;
    // subsetsWithDup(nums, res, temp, 0);
    // return res;

    /*
        1 ～ 2^0 是空数组
        2^0 ~ 2^1 是包含第一个数字的所有集合
        ...
        2^n-1 ~ 2^n 是包含n个数字的所有集合
        把重复数字看作成一个数字，则在它的那个阶段里，将所有数组依次加上每个重复的数字，共重复数字个数个。
    */

    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {{}};//{{}}很重要，不加则res返回空
    int i = 0;
    while (i < nums.size())
    {
        int rev = 0;
        while (rev+i < nums.size() && nums[rev+i] == nums[i])
            rev++;//计算重复数字的个数
        int prevSize = res.size();//得到当前res的大小
        for (int j = 0; j < prevSize; j++)//将res里的每个数组都加上当前的nums[i]
        {
            vector<int> temp = res[j];
            for (int k = 0; k < rev; k++)//每个数组都加上所有重复的数字，把重复的数字当成一个特定值，也就是看作成一个数字
            {
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        i += rev;//i往下走
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{4, 4, 1, 4};
    vector<vector<int>> res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
