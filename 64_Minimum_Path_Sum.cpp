/** 问题描述：
 *  给定一个 m*n 的格子，每个格子都有一个非负整数
 *  初始化在格子的左上角位置，目的是右下角。
 *  只能向右或者向下移动位置。
 *  找出达成目标的路径中，所有整数加起来和最小的那一条路径。
 *  返回这条路径的整数之和。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector< vector<int> >& grid)
{
    /*
        DP算法，设计一个新的path数组，初始化为原grid的左上角位置的数值。
        path数组中除第一个元素外第一行和第一列的元素初始化为grid对应位置元素加上path前一个位置元素。
        之后path中的每个元素是左边元素和上边元素中最小的那个加上grid对应位置元素。
    */
   
    if (grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector< vector<int> > path(m, vector<int>(n, grid[0][0]));
    for (int i = 1; i < m; i++)
    {
        path[i][0] = path[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        path[0][j] = path[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];
        }
    }
    return path[m-1][n-1];
}

int main(int argc, char const *argv[])
{
    int matrix[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    vector< vector<int> > grid(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = matrix[i][j];
        }
    }
    cout << minPathSum(grid);
    return 0;
}
