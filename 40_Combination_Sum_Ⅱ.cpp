/** 问题描述：
 *  给定一个没有重复数字的集合和一个目标值，从集合中找到所有和为目标值的不同的候选集合。
 *  集合中每个数字只能使用1次，而不是每种。
 *  假设数字都是正数，结果不包含完全重复的集合。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2(vector<int>& candidates, int target, vector<int>& temp, int start, vector<vector<int>>& res)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }

    for (int i = start; i != candidates.size() && target >= candidates[i]; i++)
    {
        if (i == start || candidates[i] != candidates[i-1])//i==start 保证若候选集合中存在相同数字，则结果可以包含这数字多次
                                                           //candidate[i]!=candidate[i-1] 保证重复的不再选
        {
            temp.push_back(candidates[i]);
            combinationSum2(candidates, target-candidates[i], temp, i+1, res);
            temp.pop_back();
        }
    }
}

vector< vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    /*
        先将候选集排序。
        temp为临时结果，res为最终的结果，也就是多个temp的集合。
        定义一个迭代函数，从start开始，同时每个元素都要小于等于target，大于它就没有意义。
        将每个元素堆入，而target就会减少。
        如果target减少到0，说明整个集合的和为target，所以将它压入res。
        return就说明退出，然后再调用这个函数，又重新从0位置开始找，直到找完为止。
        其中void函数中的return可有可无，结果是一样的，只是为了可读性，从那开始重新调用函数。
    */

    sort(candidates.begin(), candidates.end());
    vector< vector<int> > res;
    vector<int> temp;
    combinationSum2(candidates, target, temp, 0, res);
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector< vector<int> > res = combinationSum2(candidates, target);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
