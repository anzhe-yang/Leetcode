/** 问题描述：
 *  地下城游戏，地下城共有 M*N 个房间，每个房间有增益或者减益。
 *  骑士只能走右方或者下方，从左上角到达右下角且血量必须大于零。
 *  编写一个函数来计算骑士走最优的路线所需要的最低初始健康点数。
 */

#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon)
{
    /*
        dp算法。
        从右下角计算到左上角。
        计算第一个元素时，即右下角[m-1][n-1]元素时，需要先将它所需要的值[m][n-1]和[m-1][n]置为1。
        因为当过关斩将后HP大于零时，只需要最开始只有1HP就够了，也就是丝血通关。
        每次比较右方和下方元素，找其最小值，然后减去当前元素，计算当前dp值。
        如果小于等于0，也就是过当前关在当前血条的情况下不会死，那就只需要1HP就够了，保证不死（0就直接死了）。
        如果大于0，也就是说当前血条不够用，需要最初更多的血条。
        最终返回左上角的血条，也就是初始需要多少HP才能保证不死通关。
    */

    if (dungeon.empty() || dungeon[0].empty())
    {
        return 0;
    }
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    dp[m][n-1] = 1;
    dp[m-1][n] = 1;
    for (int i = m-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            int lastHP = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
            dp[i][j] = lastHP <= 0 ? 1 : lastHP;
        }
    }
    return dp[0][0];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> dungeon{
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    cout << calculateMinimumHP(dungeon);
    return 0;
}
