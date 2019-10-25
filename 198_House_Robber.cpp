/** 问题描述：
 *  职业强盗计划去抢劫街道上的房屋，每个屋子都有着固定的金钱。
 *  相邻的房屋的安全系统相连，如果在同一晚上抢劫相邻的两个房屋会自动报警。
 *  给定一系列非负整数代表每个屋子的金钱，判断不惊动警察的情况下一晚上能抢劫的最大金额。
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    /*
        状态方程：当前dp值表示前i个房屋能抢劫的最大金额。
        那么dp[i]就是当前房屋金额+dp[i-2]的金额和dp[i-1]的金额最大值。
    */

    if (nums.empty()) {
        return 0;
    }
    int n = nums.size();
    if (n < 2) {
        return nums[0];
    }
    vector<int> dp(n+1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    vector<int> money{1, 2, 3, 1};
    cout << rob(money) << endl;
    return 0;
}
