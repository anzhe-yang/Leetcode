/** 问题描述：
 *  字符串“PAYPALISHIRING”写成 zigzag 形式如下：
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *  其中行为3，这时字符串为“PAHNAPLSIIGYIR”。
 *  完成此类转换任务。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows)
{
    /*
        数组分为行，每行分别保存
    */

    // if (numRows == 1) 
    //     return s;

    // vector<string> temp(min(numRows, int(s.size())));//对于 vector<string> 每个元素代表一个 string，而 string 类型每个字符代表一个 char
    // int curRow = 0;
    // bool goingDown = false;

    // for (char c : s)//把新字符串数组分为 numRows 行，每行分别储存
    // {
    //     temp[curRow] += c;
    //     // if (curRow == 0 || curRow == numRows - 1) 
    //     //     goingDown = !goingDown;//当是第一个或每列最后一个时，换行
    //     // curRow += goingDown ? 1 : -1;
    //     if (curRow == 0)
    //         goingDown = true;
    //     if (curRow == numRows-1)
    //         goingDown = false;
        
    //     if (goingDown)
    //         curRow++;
    //     else
    //         curRow--;
    // }
    // string zigzag;
    // for (string row : temp) 
    //     zigzag += row;
    // return zigzag;

    /*
        二维数组保存，处理到z字斜线的字符时，做判断。
    */

    // string zigzag;
    // int cycleZig = numRows * 2 - 2;//每个 zigzag 循环所需要的字符数

    // for (int i = 0; i < numRows; i++)
    // {
    //     for (int j = 0; j+i < s.size(); j+=cycleZig)
    //     {
    //         zigzag += s[j+i];
    //         if (i != 0 && i != numRows-1 && j+cycleZig-i < s.size())//当处理每列中间的字符时
    //             zigzag += s[j+cycleZig-i];
    //     }
    // }
    // return zigzag;

    /*
        当处理z中斜线的字符时，用inter来确定位置。
    */
   
    string zigzag(s.length(), ' ');
    int res = numRows * 2 - 2;
    int k = 0;
    for (int i = 0; i < s.length(); i+=res)
        zigzag[k++] = s[i];
    for (int j = 1; j < numRows-1; j++)
    {
        int inter = j * 2;
        for (int p = j; p < s.length(); p+=inter)
        {
            zigzag[k++] = s[p];
            inter = res - inter;
        }
    }
    for (int q = numRows-1; q < s.length(); q += res)
        zigzag[k++] = s[q];
    
    return zigzag;
}

int main(int argc, char const *argv[])
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string zigzag = convert(s, numRows);
    cout << zigzag;
    return 0;
}
