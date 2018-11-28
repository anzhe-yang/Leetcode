/** 问题描述：
 *  写一个程序去填充空单元来完成一个数独问题。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) 
        if(board[x][j] == val) return false;//判断列有没有重复
    for(int y=0; y<9; y++) 
        if(board[i][y] == val) return false;//判断行有没有重复
    for(int x=0; x<3; x++)
    {
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;//判断3×3的表格内有没有重复
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if(i==9) 
        return true;//行结束
    if(j==9) 
        return solveSudoku(board, i+1, 0);//列结束，开始下一行
    if(board[i][j] != '.') 
        return solveSudoku(board, i, j+1);//如果不是空单元，进行下一步

    for(char c='1'; c<='9'; c++)
    {
        if(check(board, i, j, c))
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1))//进行数独中剩下的所有空单元数字
                return true;//检验整个数独是否符合规则，符合则跳出
            board[i][j] = '.';//不符合的话重新开始判断此单元，所以将此单元置为'.'
        }
    }
        
    return false;//如果无法解决此数独问题，说明数独初始化有问题，则返回原始表格
}

void solveSudoku(vector<vector<char>>& board)
{
    /*
        穷举法。
        查找符合规则的数字。
    */

    solveSudoku(board, 0, 0);//从起始点开始进行
}

int main(int argc, char const *argv[])
{
    char a[10][10] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    vector<vector<char>> board(9, vector<char>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            board[i][j] = a[i][j];
    }
    solveSudoku(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
