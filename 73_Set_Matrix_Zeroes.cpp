/** 问题描述：
 *  给定一个矩阵，如果其中某个元素为零，使得此元素的行和列都为零。
 *  使用原地算法，不需要额外的空间来解决。
 */

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    /*
        每一行的第一个元素存储每一行的状态，是否有零。
        每一列的第一个元素存储每一列的状态，是否有零。
        根据状态设置当前行或列是否为零。
        第一个元素，行和列状态重合，设置变量start，一个为零就为零。
    */

    int rows = matrix.size();
    int cols = matrix[0].size();
    int start = 1;

    //设置每行每列的状态
    for (int i = 0; i < rows; i++) 
    {
        if (matrix[i][0] == 0) 
            start = 0;//处理第一个元素
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)//只要有元素为零
                matrix[i][0] = matrix[0][j] = 0;//设置状态为零
        }
    }
    //根据状态置相应行和列的矩阵元素为零
    for (int i = rows - 1; i >= 0; i--) 
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)//状态为零
                matrix[i][j] = 0;//当前行列每个元素为零
        }
        if (start == 0)//处理第一个元素
            matrix[i][0] = 0;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {0},
        {2},
        {3}
    };
    setZeroes(matrix);
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
