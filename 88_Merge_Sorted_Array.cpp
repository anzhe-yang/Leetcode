/** 问题描述：
 *  给定两个有序的整数序列 nums1 nums2 ，将 nums2 归并到 nums1 中排成一个有序序列。
 *  假设 nums1 拥有足够多的空间，非有效数字用 0 表示。
 */

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    /*
        从后往前开始判断，定义一个位置变量pos，从nums1的最后一个位置开始。
        如果m=0，则通过另一个while循环直接将nums2赋值给nums1。
    */
   
    int i = m-1, j = n-1;
    int pos = nums1.size()-1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[pos] = nums1[i];
            i--;
        }
        else
        {
            nums1[pos] = nums2[j];
            j--;
        }
        pos--;
    }
    while (j >= 0)
    {
        nums1[pos] = nums2[j];
        j--;
        pos--;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums1{0, 0, 0};
    int m = 0;
    vector<int> nums2{2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}