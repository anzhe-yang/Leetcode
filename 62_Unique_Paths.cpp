/** 问题描述：
 *  一个机器人被初始化在一个 m*n 的矩阵中的左上角位置。
 *  机器人每次只能向下或者向右移动，直到移动到右下角的位置。
 *  计算出机器人能够完成的不同的道路有多少。
 *  假设 m 和 n 最多为 100。
 */

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    /*
        DP动态规划基础问题。
        若矩阵大小为m和n，则需要向下走m-1个格子，向右走n-1个格子。
        path[i][j]=path[i-1][j]+path[i][j-1]。
        且初始化path[0][j]=path[i][0]=1。
        下面的写法是优化后的写法。
        时间复杂度O(n^2)，空间复杂度O(1)。
    */

    // if (m > n)
    //     return uniquePaths(n, m);
    // vector<int> path(m, 1);
    // for (int j = 1; j < n; j++)
    // {
    //     for (int i = 1; i < m; i++)
    //         path[i] += path[i-1];
    // }
    // return path[m-1];

    //基础DP算法
    vector< vector<int> > path(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                path[i][j] = 1;
            else if (i == 0 && j != 0)
                path[i][j] = path[i][j-1];
            else if (i != 0 && j == 0)
                path[i][j] = path[i-1][j];
            else
                path[i][j] = path[i-1][j] + path[i][j-1];
        }
    }
    return path[m-1][n-1];
}

int main(int argc, char const *argv[])
{
    int m = 3, n = 2;
    cout << uniquePaths(m, n);
    return 0;
}
