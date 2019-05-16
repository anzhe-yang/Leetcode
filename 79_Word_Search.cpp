/** 问题描述：
 *  给定一个 2D 的字母数组，返回单词是否存在于这个数组中。
 *  该单词可以由顺序相邻的单元的字母构成，其中“相邻”单元是水平或垂直相邻的单元。
 *  相同的字母单元格不得多次使用。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exist(vector<vector<char>>& board, string word, int x, int y, int pos, int m, int n, int len)
{
    char cur = board[x][y];
    bool res = false;
    if (cur != word[pos])
        return false;
    if (pos == len-1)
        return true;
    board[x][y] = '*';
    if(x > 0) res = exist(board, word, x-1, y, pos+1, m, n, len);
    if(!res && x < m-1) res = exist(board, word, x+1, y, pos+1, m, n, len);
    if(!res && y > 0)   res = exist(board, word, x, y-1, pos+1, m, n, len);
    if(!res && y < n-1) res = exist(board, word, x, y+1, pos+1, m, n, len);
    board[x][y] = cur;
    return res;
}

bool exist(vector<vector<char>>& board, string word)
{
    /*
        回溯法。
        首先找到第一个词，之后利用循环函数验证每个词cur是否等于word[pos]。
        之后分别从左、右、上、下四个位置找下一个词。
        都找到了，则pos=len-1，则返回。
        有一个没找到就返回false。
    */
   
    int m = board.size();
    int n = board[0].size();
    int len = word.length();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (exist(board, word, i, j, 0, m, n, len))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << boolalpha << exist(board, word);
    return 0;
}
