/** 问题描述：
 *  给定一个无序整数序列，找到其中最长的连续元素序列。
 *  算法时间复杂度为 O(n) 。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void mergeSort(vector<int>& nums, int left, int right)
{
    if (left < right)
    {
        int mid = (left+right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        int i = left, j = mid + 1;
        int k = 0;
        vector<int> temp(nums.size());
        while (i < mid+1 && j < right+1)
        {
            if (nums[i] > nums[j])
                temp[k++] = nums[j++];
            else
                temp[k++] = nums[i++];
        }
        while (i < mid+1)
        {
            temp[k++] = nums[i++];
        }
        while (j < right+1)
            temp[k++] = nums[j++];

        for (i = 0, j = left; j < right+1; i++, j++)
            nums[j] = temp[i];
    }
}

int longestConsecutive(vector<int>& nums)
{
    /*
        先归并排序，O(logN)。
        之后在遍历一次数组，O(N)。
        找最大的每个差为1的序列长度。
    */

    // if (nums.empty())
    //     return 0;
    // if (nums.size() == 1)
    //     return 1;
    // int len = nums.size();
    // mergeSort(nums, 0, len-1);
    // int maxLen = 1;
    // int curLen = 1;
    // for (int i = 0; i < len-1; i++)
    // {
    //     if (nums[i+1] - nums[i] == 1)
    //     {
    //         curLen++;
    //     }
    //     else if (nums[i+1] - nums[i] > 1)
    //     {
    //         maxLen = max(maxLen, curLen);
    //         curLen = 1;
    //     }
    // }
    // maxLen = max(maxLen, curLen);
    // return maxLen;

    /*
        将数组保存在set变量里。
        遍历数组中每一个元素，复杂度为O(n)。
        如果i-1不在set变量里，则查找i+1，如果找到，则找i+1+1，一直到找不到位置，长度就为i+1+1+...+1 - i。
    */
   
    int maxLen = 0;
    unordered_set<int> map(nums.begin(), nums.end());
    for (int i : nums)
    {
        if (map.find(i-1) == map.end())
        {
            int tmp = i+1;
            while (map.find(tmp) != map.end())
            {
                tmp++;
            }
            maxLen = max(maxLen, tmp-i);
        }
    }
    return maxLen;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{100, 4, 200, 1, 3, 2};
    // vector<int> nums{1, 2, 0, 1};
    cout << longestConsecutive(nums);
    return 0;
}
