/** 问题描述：
 *  给定一组非负整数数组，被初始化在第一个位置元素上。
 *  每个数组中的元素表示了你能跳跃的最大步数。
 *  判断是否能刚好到达最后一个元素位置。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums, int pos, int len)
{
    if (pos == len-1)
        return true;

    int maxDis = min(pos + nums[pos], len-1);
    for (int i = maxDis; i > pos; i--)
    {
        if (canJump(nums, i, len))
            return true;
    }
    return false;
}

bool canJump(vector<int>& nums)
{
    /*
        利用回溯法。
    */
   
    int len = nums.size();
    return canJump(nums, 0, len);

    /*
        curPos代表了当前所移动到的位置，maxDis代表了当前所能达到的最远位置。
        cur+nums[cur]代表了能跳跃的最远位置，随着cur递增，max也在增加。
        如果到了最后cur与数组长度相等，则表示能够达到目标。
        否则不能达到目标。
    */

    // int curPos = 0;
    // int len = nums.size();
    // for (int maxDis = 0; curPos < len && curPos <= maxDis; curPos++)
    //     maxDis = max(curPos + nums[curPos], maxDis);
    // return curPos == len;
}

int main(int argc, char const *argv[])
{
    int num[] = {2, 3, 1, 1, 4};
    vector<int> nums(num, num+5);
    cout << boolalpha << canJump(nums);
    return 0;
}
