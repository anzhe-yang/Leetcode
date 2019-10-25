/** 问题描述：
 *  给定一个仅包含正整数的非空数组，判断是否可以将其分成两个和一样的子数组。
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool dfs(vector<int> &nums, int start, int target) {
    if (target <= 0) {
        return target == 0;
    }

    for (int i = start; i < nums.size(); i++) {
        if (dfs(nums, i+1, target-nums[i])) {
            return true;
        }
    }
    return false;
}

bool canPartition(vector<int>& nums) {
    /*
        常规dfs搜索解法。
        先求目标值，即数组和的一半。
        然后每次将目标值减去当前元素，若目标值刚好为0，说明可以分为两组。
        如果小于0，则不可以。
    */

    // int n = nums.size();
    // if (n < 2) {
    //     return false;
    // }
    // int total = 0;
    // for (int num : nums) {
    //     total += num;
    // }
    // if (total % 2 != 0) {
    //     return false;
    // }
    // return dfs(nums, 0, total/2);

    /*
        dp解法，遍历每一个元素。
        状态方程为：当前数字作为和，即target，是否可以有两组子数组和都为target。
        所以最终判断和为target时，是否有两个子数组和为target。
    */

    if (nums.size() < 2) {
        return false;
    }
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % 2 != 0) {
        return false;
    }
    int target = total / 2;
    vector<bool> dp(target+1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i-num];
        }
    }
    return dp[target];
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 5};
    cout << boolalpha << canPartition(nums) << endl;
    return 0;
}
