/** 问题描述：
 *  给定一个 m*n 的矩阵，按照顺时针螺旋顺序返回其中所有元素。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector< vector<int> >& matrix)
{
    /*
        定义两个方向响亮dirRow和dirCol，定义了每次移动的方向。
        isCover布尔数组定义了当前元素是否被使用过。
    */

    vector<int> res;
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0)
        return res;
    
    bool isCover[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            isCover[i][j] = false;
    
    int dirRow[] = {0, 1, 0, -1};
    int dirCol[] = {1, 0, -1, 0};
    int row = 0, col = 0, count = 0;
    for (int i = 0; i < m*n; i++)
    {
        res.push_back(matrix[row][col]);
        isCover[row][col] = true;
        int tmpRow = row + dirRow[count];
        int tmpCol = col + dirCol[count];
        if (0 <= tmpRow && tmpRow < m && 0 <= tmpCol && tmpCol < n && !isCover[tmpRow][tmpCol])
        {
            row = tmpRow;
            col = tmpCol;
        }
        else
        {
            count = (count+1) % 4;
            row += dirRow[count];
            col += dirCol[count];
        }
    }
    return res;

    /*
        定义4个方向的当前极限值：上下左右。
        在这个范围内进行工作，res的大小达到时停止。
    */

    // vector<int> res;
    // int row = matrix.size();
    // int col = matrix[0].size();
    // if (row == 0)
    //     return res;

    // int upper = 0, bottom = row-1, left = 0, right = col-1;
    // while (res.size() < row*col)
    // {
    //     for (int i = left; i <= right; i++)
    //         res.push_back(matrix[upper][i]);
        
    //     for (int i = upper+1; i <= bottom; i++)
    //         res.push_back(matrix[i][right]);
        
    //     for (int i = right-1; i >= left; i--)
    //         res.push_back(matrix[bottom][i]);
        
    //     for (int i = bottom-1; i >= upper+1; i--)
    //         res.push_back(matrix[i][left]);

    //     upper++;
    //     bottom--;
    //     left++;
    //     right--;
    // }
    // return res;
}

int main(int argc, char const *argv[])
{
    int num[3][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    vector< vector<int> > matrix(3, vector<int>(3));
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            matrix[i][j] = num[i][j];

    vector<int> res = spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}
