/** 问题描述：
 *  给定一个整数数组，返回两个数字的索引，使它们相加到特定目标。
 *  假设每个输入只有一个解决方案，同时不会使用相同的元素两次。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> Two_Sum(vector<int> &numbers, int target)
{
    /*
        固定第一个数，从第二个数开始找出满足条件的组合。
    */
   
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    vector<int> res = Two_Sum(nums, target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}