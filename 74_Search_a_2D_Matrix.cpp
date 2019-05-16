/** 问题描述：
 *  从一个矩阵中寻找一个值。
 *  这个矩阵中每一行的整数都是从左到右排序好的。
 *  当前行第一个元素是大于前一行最后一个元素。
 */

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector< vector<int> >& matrix, int target)
{
    /*
        基础方法。
    */

    // int row = matrix.size();
    // int col = matrix[0].size();
    // for (int i = 0; i < row; i++)
    // {
    //     if (matrix[i][0] <= target && matrix[i][col-1] >= target)
    //     {
    //         for (int j = 0; j < col; j++)
    //         {
    //             if (matrix[i][j] == target)
    //                 return true;
    //         }
    //     }
    // }

    /*
        将二维矩阵看作是一维矩阵。
        a[x][y] = a[x*col+y]
        a[p] = a[p/col][p%col]
    */

    // if (matrix.empty() || matrix[0].empty())
    //     return false;
    // int m = matrix.size();
    // int n = matrix[0].size();
    // int left = 0, right = m*n-1;
    // while (left < right)
    // {
    //     int mid = (left + right - 1) / 2;
    //     if (matrix[mid/m][mid%m] < target)
    //         left = mid+1;
    //     else
    //         right = mid;
    // }
    // if (matrix[right/n][right%n] == target)
    //     return true;
    // return false;

    /*
        巧妙方法，比化一维矩阵快。
        将a定义为行，b定义为列。
        a从零开始，b从最后开始。
        找目标。
    */
    if (matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int a = 0, b = n - 1;
    while (a < m && b >= 0)
    {
        if (matrix[a][b] < target)
            a++;
        else if (matrix[a][b] > target)
            b--;
        else
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector< vector<int> > matrix{
        {1, 1}
    };
    int target = 2;
    cout << boolalpha << searchMatrix(matrix, target);
    return 0;
}
