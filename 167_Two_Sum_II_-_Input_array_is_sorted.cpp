/** 问题描述：
 *  给定一个前序整数序列，找到之和等于目标值的两个数。
 *  返回两个数的索引，且第一个索引必须小于第二个索引。
 *  索引从 1 开始。
 *  假设只有一种解决方案，且不使用同一个数字两次。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    /*
        定义两个指针。
        一个从前往后找，一个从后往前找。
    */
   
    vector<int> res;
    int len = numbers.size();

    int i = 0, j = len-1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            res.push_back(i+1);
            res.push_back(j+1);
            return res;
        }
        else if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        } 
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> numbers{2, 7, 9, 15};
    int target = 16;
    vector<int> res = twoSum(numbers, target);
    for (int s : res)
        cout << s << " ";
    return 0;
}
