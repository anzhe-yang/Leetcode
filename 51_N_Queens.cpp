/** 问题描述：
 *  N 个皇后问题研究的是如何将 N 个皇后放置在 n*n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *  同一行、同一列、同一斜线上的皇后会相互攻击。
 *  给定一个整数 n ，返回所有不同的 N 皇后问题的解决方案。
 *  每一种解法包含一个明确的 N 皇后问题的棋子放置方案，该方案中 Q 和 . 分别代表了皇后和空位。
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

void solveNQueens(vector< vector<string> >& res, vector<string>& nQueens, int row, int &n)
{
    if (row == n)
    {
        res.push_back(nQueens);
        return ;
    }

    for (int col = 0; col != n; col++)
    {
        if (isValid(nQueens, row, col, n))
        {
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, row+1, n);
            nQueens[row][col] = '.';
        }
    }
}

vector< vector<string> > solveNQueens(int n)
{
    /*
        利用回溯算法进行递归。
        首先建立一个空棋盘，全是.。
        之后从每一行开始，如果当前位置可以插入皇后，则插入，然后行加1。
        判断是否符合规定通过判断当前列，45度斜线，135度斜线是否有皇后。
        递归调用函数。
        如果最后此棋盘不符合规定，则把位置都设置为.，并重来。
        如果行调用完了，将当前结果加入数组里。
    */

    vector< vector<string> > res;
    vector<string> nQueens(n, string(n, '.'));
    solveNQueens(res, nQueens, 0, n);
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    vector< vector<string> > res = solveNQueens(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
