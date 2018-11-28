/** 问题描述：
 *  给定一个顺序为升序的整数数组，找到目标值的起始位置和终止位置。
 *  算法的运行复杂度必须为 O(logN) 。
 *  如果数组中没有找到目标，返回 [-1, -1]。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    /*
        二分法搜索。
        第一次搜索目标值的起始位置。
        第二次搜索目标值的终止位置。
    */
   
    vector<int> res;
    int len = nums.size();

    int low = 0, high = len;
    while (low < high) 
    {
		int mid = low + ((high - low) >> 1); // >>1 等于除以2
		if (nums[mid] < target) 
			low = mid + 1;
         else
			high = mid;
	}
    int start = low;

    if (start == len || nums[start] != target)
    {
        return vector<int>{-1, -1};
    }

    low = 0, high = len;
    target = target+1;
    while (low < high) 
    {
		int mid = low + ((high - low) >> 1);
		if (nums[mid] < target) 
			low = mid + 1;
         else
			high = mid;
	}
    int end = low-1;

    res.push_back(start);
    res.push_back(end);
    return res;
}

int main(int argc, char const *argv[])
{
    int num[] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(num, num+6);
    int target = 8;
    vector<int> res = searchRange(nums, target);
    cout << res[0] << ", " << res[1];
    cin.get();
    return 0;
}
