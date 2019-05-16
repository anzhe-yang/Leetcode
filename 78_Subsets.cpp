/** 问题描述：
 *  给定一系列不同整数，返回所有可能的子集，包括零子集。
 */

#include <iostream>
#include <vector>

using namespace std;

// void subsets(vector< vector<int> >& res, vector<int>& nums, vector<int>& temp, int pos)
// {
//     res.push_back(temp);
//     for (int i = pos; i < nums.size(); i++)
//     {
//         temp.push_back(nums[i]);
//         subsets(res, nums, temp, pos+1);
//         temp.pop_back();
//     }
// }
// vector< vector<int> > subsets(vector<int>& nums)
// {
//     vector< vector<int> > res;
//     vector<int> temp;
//     subsets(res, nums, temp, 0);
//     return res;
// }

vector< vector<int> > subsets(vector<int>& nums)
{
    /*
        迭代法。
        先对第一个元素进行处理。
        之后对第二个元素进行处理。
        之后对第一个和第二个元素进行处理。
        依次类推。
    */

    vector< vector<int> > res(1, vector<int>());
    for (int i = 0; i < nums.size(); i++)
    {
        int n = res.size();
        for (int j = 0; j < n; j++)
        {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3};
    vector< vector<int> > res = subsets(nums);
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
