/** 问题描述：
 *  给定一个非负索引 k<=33 ，返回杨辉三角形的第 k 行所有元素，从第零行开始计算。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    /*
        杨辉三角性质，每一行第一个和最后一个元素为1。
        其它元素为左上元素加上元素的和。
        返回最后一行的所有元素。
    */
   
    vector<vector<int>> res(rowIndex+1, vector<int>(0));
    int cols = 1;
    for (int i = 0; i <= rowIndex; i++)
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
    return res[rowIndex];
}

int main(int argc, char const *argv[])
{
    int rowIndex = 3;
    vector<int> res = getRow(rowIndex);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
