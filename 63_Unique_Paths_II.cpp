/** 问题描述：
 *  一个机器人被初始化在一个 m*n 的矩阵中的左上角位置。
 *  机器人每次只能向下或者向右移动，直到移动到右下角的位置。
 *  假设在矩阵中会存在一些障碍物。
 *  矩阵中数值 1 代表是障碍物，数值 0 代表为空。
 *  计算出机器人能够完成的不同的道路有多少。
 *  假设 m 和 n 最多为 100。
 */

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
{
    /*
        首先判断矩阵是否为空，或者矩阵的左上角元素是否为1。
        其次建立一个m+1,n+1的零矩阵。
        不考虑第一行和第一列元素。
        将[0,1]位置的元素设为1，让矩阵从[0,0]到[1,1]只有一条路可以走。
        之后如果原障碍矩阵当前元素为0，则对左边和上边的元素求和。
        如果为1，则新矩阵当前元素位置为0，此路不通。
        返回新矩阵最后一个元素。
    */

    if (obstacleGrid.empty() || obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector< vector<int> > paths(m+1, vector<int>(n+1, 0));
    paths[0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[i-1][j-1] == 0)
            {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
    }
    return paths[m][n];
}

int main(int argc, char const *argv[])
{
    int grid[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    vector< vector<int> > obstacleGrid(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            obstacleGrid[i][j] = grid[i][j];
        }
    }
    cout << uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
