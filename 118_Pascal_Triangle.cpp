/** 问题描述：
 *  给定一个非负正数 numRows ，生成一个杨辉三角形。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    /*
        杨辉三角性质，每一行第一个和最后一个元素为1。
        其它元素为左上元素加上元素的和。
    */
   
    vector<vector<int>> res(numRows, vector<int>(0));
    if (numRows < 1)
        return res;
    int cols = 1;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == 0 || j == cols-1)
            {
                res[i].push_back(1);
            }
            else
            {
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }    
        }
        cols++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int numRows = 5;
    vector<vector<int>> res = generate(numRows);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        if (i < numRows-1)
            cout << endl;
    }
    return 0;
}
