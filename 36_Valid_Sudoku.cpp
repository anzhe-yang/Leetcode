/** 问题描述：
 *  确定一个 9×9 的数独表是否有效，仅根据以下规则：
 *  1. 每行必须包含数字1-9，且不重复。
 *  2. 每列必须包含数字1-9，且不重复。
 *  3. 网格中9个 3×3 的子框中必须包含数字1-9，且不重复。
 *  假设数独表可以部分填充，空单元填充字符 ‘.’。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSudoku(vector< vector<char> >& board)
{
    /* 
        temp临时数组，如果从这个数组中找到一样的，则返回false。
    */
   
    int left = board.size();//9
    int right = board[0].size();//9
    vector<int> temp;

    for (int i = 0; i < left; i++)
    {
        for (int j = 0; j < right; j++)
        {
            vector<int>::iterator rep = find(temp.begin(), temp.end(), board[i][j]);
            if (rep != temp.end())
                return false;

            if (board[i][j] != '.')
                temp.push_back(board[i][j]);
        }
        temp.clear();
    }

    for (int i = 0; i < right; i++)
    {
        for (int j = 0; j < left; j++)
        {
            vector<int>::iterator rep = find(temp.begin(), temp.end(), board[j][i]);
            if (rep != temp.end())
                return false;

            if (board[j][i] != '.')
                temp.push_back(board[j][i]);
        }
        temp.clear();
    }

    for (int i = 0; i < left-2; i+=3)
    {
        for (int j = 0; j < right-2; j+=3)
        {
            for (int m = i; m < i+3; m++)
            {
                for (int n = j; n < j+3; n++)
                {
                    vector<int>::iterator rep = find(temp.begin(), temp.end(), board[m][n]);
                    if (rep != temp.end())
                        return false;

                    if (board[m][n] != '.')
                        temp.push_back(board[m][n]); 
                }
            }
            temp.clear();
        }
    }

    return true;


    /*
        定义三个数组，分别代表行、列、3×3的表格。
        若出现1，则说明那个位置有对应的数字，则说明重复，返回false。
    */

    // int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
    // for(int i = 0; i < board.size(); i++)
    //     for(int j = 0; j < board[i].size(); j++)
    //         if(board[i][j] != '.')
    //         {
    //             int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
    //             if(used1[i][num] || used2[j][num] || used3[k][num])
    //                 return false;
    //             used1[i][num] = used2[j][num] = used3[k][num] = 1;
    //         }    
    // return true;
}

int main(int argc, char const *argv[])
{
    // vector< vector<char> > board{
    //     {"5","3",".",".","7",".",".",".","."},
    //     {"6",".",".","1","9","5",".",".","."},
    //     {".","9","8",".",".",".",".","6","."},
    //     {"8",".",".",".","6",".",".",".","3"},
    //     {"4",".",".","8",".","3",".",".","1"},
    //     {"7",".",".",".","2",".",".",".","6"},
    //     {".","6",".",".",".",".","2","8","."},
    //     {".",".",".","4","1","9",".",".","5"},
    //     {".",".",".",".","8",".",".","7","9"}
    // };
    char a[10][10] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    vector<vector<char>> board(9, vector<char>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            board[i][j] = a[i][j];
    }
    cout << boolalpha << isValidSudoku(board);
    return 0;
}
