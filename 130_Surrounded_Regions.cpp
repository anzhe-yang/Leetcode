/** 问题描述：
 *  给定一个 2D 棋盘，仅包含 X 和 O ，将 X 所包围的区域覆盖掉。
 *  包围区域不应位于边界上，即边界上的 O 不会被翻转为 X 。
 *  任何不在边界上且未连接到边界上的 O 会翻转为 X 。
 */

#include <iostream>
#include <vector>

using namespace std;

void checkBoundaryO(vector<vector<char>> &board, int row, int col, int rows, int cols)
{
    if (board[row][col] == 'O')
    {
        board[row][col] = 'Y';
        if (row+1 < rows)
            checkBoundaryO(board, row+1, col, rows, cols);
        if (row-1 > 0)
            checkBoundaryO(board, row-1, col, rows, cols);
        if (col+1 < cols)
            checkBoundaryO(board, row, col+1, rows, cols);
        if (col-1 > 0)
            checkBoundaryO(board, row, col-1, rows, cols);
    }
}

void solve(vector<vector<char>>& board)
{
    /*
        先将边界上的O和连接边界O的所有O变为Y。
        之后将其余所有O变为X。
        最后将Y变为O。
    */
   
    if (!board.size())
        return ;
    int rows = board.size();
    int cols = board[0].size();

    for (int row = 0; row < rows; row++)
    {
        checkBoundaryO(board, 0, 0, rows, cols);
        if (cols > 1)
            checkBoundaryO(board, 0, cols-1, rows, cols);
    }
    for (int col = 1; col < cols-1; col++)
    {
        checkBoundaryO(board, 0, 1, rows, cols);
        if (rows > 1)
            checkBoundaryO(board, rows-1, 1, rows, cols);
    }
    for (int row = 1; row < rows-1; row++)
    {
        for (int col = 1; col < cols-1; col++)
        {
            if (board[row][col] == 'O')
            {
                board[row][col] = 'X';
            }
        }
    }
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == 'Y')
            {
                board[row][col] = 'O';
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // vector<vector<char>> board{
    //     {'X', 'X', 'X', 'X'},
    //     {'X', 'O', 'O', 'X'},
    //     {'X', 'X', 'O', 'X'},
    //     {'X', 'O', 'O', 'X'}
    // };
    vector<vector<char>> board{{'X'}};
    solve(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
