/** 问题描述：
 *  职业强盗计划去抢劫街道上的房屋，每个屋子都有着固定的金钱。
 *  所有的房屋位置构成一个循环，也就是在一个圈内，意味着最后一个房屋与第一个房屋相邻。
 *  相邻的房屋的安全系统相连，如果在同一晚上抢劫相邻的两个房屋会自动报警。
 *  给定一系列非负整数代表每个屋子的金钱，判断不惊动警察的情况下一晚上能抢劫的最大金额。
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    /*
        调用两次不循环找最大金额的方法。
        第一次从0到n-2。
        第二次从1到n-1。
        找这俩最大的。
    */

    if (nums.empty()) {
        return 0;
    }
    int n = nums.size();
    if (n < 2) {
        return nums[0];
    }

    int pre = 0, cur = 0;
    for (int i = 0; i < n-1; i++) {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    int res1 = cur;

    pre = 0, cur = 0;
    for (int i = 1; i < n; i++) {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    int res2 = cur;

    return max(res1, res2);
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}
