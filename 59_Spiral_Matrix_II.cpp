/** 问题描述：
 *  给定一个正整数，生成一个方形矩阵，用顺时针螺旋顺序填充 1 到 n 的平方个元素。
 */

#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generateMatrix(int n)
{
    /*
        建立上、下、左、右四个极限值。
        初始化n*n矩阵，并初始化为0。
    */
   
    vector< vector<int> > res(n, vector<int>(n, 0));
    int upper = 0;
    int bottom = n-1;
    int left = 0;
    int right = n-1;
    int sign = 1;
    while (sign <= n*n)
    {
        for (int i = left; i <= right && sign <= n*n; i++)
        {
            res[upper][i] = sign++;
        }
        for (int j = upper+1; j <= bottom && sign <= n*n; j++)
        {
            res[j][right] = sign++;
        }
        for (int i = right-1; i >= left && sign <= n*n; i--)
        {
            res[bottom][i] = sign++;
        }
        for (int j = bottom-1; j > upper && sign <= n*n; j--)
        {
            res[j][left] = sign++;
        }
        upper++;
        bottom--;
        left++;
        right--;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector< vector<int> > res = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
