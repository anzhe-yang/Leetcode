/** 问题描述：
 *  给定一个整数 n ，返回不同解决方案的数量。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& nQueens, int row, int col, int &n)
{
    for (int i = 0; i != row; i++)
        if (nQueens[i][col] == 'Q')
            return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (nQueens[i][j] == 'Q')
            return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (nQueens[i][j] == 'Q')
            return false;
    
    return true;
}

void solveNQueens(vector<string>& nQueens, int row, int &n, int &res)
{
    if (row == n)
    {
        res++;
        return ;
    }

    for (int col = 0; col != n; col++)
    {
        if (isValid(nQueens, row, col, n))
        {
            nQueens[row][col] = 'Q';
            solveNQueens(nQueens, row+1, n, res);
            nQueens[row][col] = '.';
        }
    }
}

int totalNQueens(int n)
{
    /*
        利用回溯算法进行递归。
        首先建立一个空棋盘，全是.。
        之后从每一行开始，如果当前位置可以插入皇后，则插入，然后行加1。
        判断是否符合规定通过判断当前列，45度斜线，135度斜线是否有皇后。
        递归调用函数。
        如果最后此棋盘不符合规定，则把位置都设置为.，并重来。
        如果行调用完了，解决方案递增。
    */
    vector<string> nQueens(n, string(n, '.'));
    int res = 0;
    solveNQueens(nQueens, 0, n, res);
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    cout << totalNQueens(n);
    return 0;
}