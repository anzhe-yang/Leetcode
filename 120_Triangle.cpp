/** 问题描述：
 *  给定一个三角形二维数组，从顶部到底部找到一个元素之和最大的路径。
 *  每一步只能移动到相邻列的元素。
 */

#include <iostream>
#include <vector>

using namespace std;

void minSum(vector<vector<int>>& triangle, int& sum, int curSum, int curRow, int curCol)
{
    if (curRow == triangle.size())
    {
        sum = min(sum, curSum);
        return ;
    }

    curSum += triangle[curRow][curCol];
    minSum(triangle, sum, curSum, curRow+1, curCol);
    curSum -= triangle[curRow][curCol];
    if (curCol < curRow)
    {
        curSum += triangle[curRow][curCol+1];
        minSum(triangle, sum, curSum, curRow+1, curCol+1);
    }
}

int minimumTotal(vector<vector<int>>& triangle)
{
    /*
        回溯法。
        42/43passed。
        时间超限。
    */

    // if (triangle.size() == 0)
    //     return 0;
    // int sum = INT_MAX;
    // minSum(triangle, sum, 0, 0, 0);
    // return sum;

    /*
        DP法。
        从底而上：倒数第二层开始，每个元素对应位置的最小和路径即为：取正下方元素和右下方元素的最小和路径中较小的那个，再加上当前元素。
        即minPath[row][col] = min(minPath[row+1][col], minPath[row+1][col+1]) + triangle[row][col]。
        简化一下目标函数，对于第row层，minPath[col] = min(minPath[col], minPath[col+1]) + triangle[row][col]。
        因为minPath[row+1]对于第row+1层是没用的，再计算第row层才有用，所以可以简化。
    */

    int rows = triangle.size();
    vector<int> minPath(triangle.back());
    for (int row = rows-2; row >= 0; row--)
    {
        for (int col = 0; col <= row; col++)
        {
            minPath[col] = min(minPath[col], minPath[col+1]) + triangle[row][col];
        }
    }
    return minPath[0];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> triangle{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << minimumTotal(triangle);
    return 0;
}
