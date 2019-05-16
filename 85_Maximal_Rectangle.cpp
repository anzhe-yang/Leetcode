/** 问题描述：
 *  给定一个被 0 1 充满的 2D 矩阵，找到仅包含 1 的最大矩形面积，并返回面积。
 */

#include <iostream>
#include <vector>

using namespace std;

// void maximalRectangle(vector< vector<char> > matrix, int& rect, int i, int j, int row, int col)
// {
//     int tmp = 1, countRow = 1, countCol = 1;
//     int tmpRow = i, tmpCol = j;
//     while (tmpRow+1 < row)
//     {
//         if (matrix[++tmpRow][tmpCol] == '1')
//             countRow++;
//         else
//             break;
//     }
//     while (tmpCol+1 < col)
//     {
//         if (matrix[tmpRow][++tmpCol] == '1')
//             countCol++;
//         else
//             break;
//     }
//     tmp = countRow * countCol;
//     rect = max(rect, tmp);
// }

int maximalRectangle(vector< vector<char> >& matrix)
{
    /*
        循环判断每一个元素所在矩阵的最大面积。
    */

    // if (matrix.empty() && matrix[0].empty())
    //     return 0;
    
    // int row = matrix.size();
    // int col = matrix[0].size();
    // int rect = 0;
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if (matrix[i][j] == '1')
    //         {
    //             maximalRectangle(matrix, rect, i, j, row, col);
    //         }
    //     }
    // }
    // return rect;

    /*
        DP算法。
        最终每个元素所包含的最大面积为(right[i]-left[i])*height[i]。
    */

    if (matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left, n, 0);//将left数组填充n个元素，每个元素填充为0
    fill_n(right, n, n);
    fill_n(height, n, 0);
    int maxRect = 0;
    for (int i = 0; i < m; i++)
    {
        int cur_left = 0, cur_right = n;//left为从左往右数，如果有1，则+1。
                                        //right为从右往左数，如果有1，则-1。
        //最终right数组里为当前列中，当前元素所在的那个矩形的最大面积，并被列数n减去，共有n个元素。
        for (int j = n-1; j >= 0; j--)
        {
            if (matrix[i][j] == '1')
                right[j] = min(right[j], cur_right);
            else
            {
                right[j] = n;
                cur_right = j;
            }
        }
        //最终left数组里为当前列中，当前元素所在的那个矩形的最大面积，共有n个元素。
        //最终height数组里为每一列中，包含一个1则加1，共有n个元素。
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == '1')
            {
                height[j]++;
                left[j] = max(left[j], cur_left);
            }
            else
            {
                height[j] = 0;
                left[j] = 0;
                cur_left = j+1;
            }
            maxRect = max(maxRect, (right[j]-left[j])*height[j]);//找最大的面积
        }
    }
    return maxRect;
}

int main(int argc, char const *argv[])
{
    vector< vector<char> > matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}
