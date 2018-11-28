/** 问题描述：
 *  给定一个2D矩阵，表示为一个图像。
 *  将图像顺时针旋转 90 度。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    /*
        简单方法，先定义一个临时数组，将每个元素旋转到对应位置上。
        之后再传送会原数组。
    */

    // int n = matrix.size();
    // vector<vector<int>> temp(n, vector<int>(n, 0));
    // int row = 0;
    // for (int i = n-1; i >= 0; i--)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         temp[j][i] = matrix[row][j];
    //     }
    //     row++;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         matrix[i][j] = temp[i][j];
    // }

    /*
        常规方法，先将数组倒立，即每行发生变化，每列不改变。
        之后交换对角线元素即可。
    */
   
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
