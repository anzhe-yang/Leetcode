/** 问题描述：
 *  给定两个排好序的数组 nums1 和 nums2，大小为 m 和 n。
 *  找到包含两个数组中所有数的中间值，整体的运行时间应为 O(log(m+n))。
 *  假设两个数组不可能同时为空。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    /*
        排序后按照单数和双数分别进行处理。
    */
   
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());

    if (nums1.size() & 1)//判断大小是否为单数
        return nums1[(nums1.size()+1)/2 - 1];
    else
        return ( nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2] ) / 2.0;
}

int main(int argc, char const *argv[])
{
    double n1[] = {2, 2};
    int m = sizeof(n1) / sizeof(int);
    double n2[] = {0, 3};
    int n = sizeof(n2) / sizeof(int);
    vector<int> nums1(n1, n1+m);
    // nums1.insert(nums1.begin(), n1, n1+m+1);
    vector<int> nums2(n2, n2+n);
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median is " << median;
    return 0;
}
