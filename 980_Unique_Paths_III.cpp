/** 问题描述：
 *  在一个 2D 矩阵中，有 4 中类型的数值：
 *  1 代表起点
 *  2 代表终点
 *  0 代表可以走的路径
 *  -1 代表不可走的路径
 *  4 个方向都可以行走，从起点走到终点，但必须每个可以走的点都要经过。
 *  返回所有可以走的路径个数。
 */

#include <iostream>
#include <vector>

using namespace std;

int numOfPaths(vector<vector<int>> &grid, int x, int y, int nums) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) {
        return 0;
    }
    if (grid[x][y] == 2) {
        if (nums == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    grid[x][y] = -1;
    int res = numOfPaths(grid, x-1, y, nums-1) + numOfPaths(grid, x, y+1, nums-1) +
            numOfPaths(grid, x+1, y, nums-1) + numOfPaths(grid, x, y-1, nums-1);
    grid[x][y] = 0;
    return res;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int start_x = -1, start_y = -1;
    int nums = 1;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 0) {
                nums++;
            }
        }
    }
    return numOfPaths(grid, start_x, start_y, nums);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 2}
    };
    cout << uniquePathsIII(grid) << endl;
    return 0;
}
