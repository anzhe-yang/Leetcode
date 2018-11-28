/** 问题描述：
 *  给定一个字符串包含数字 2-9，返回该数字可能表示的所有字母组合。
 *  2：a b c
 *  3：d e f
 *  4：g h i
 *  5：j k l
 *  6：m n o
 *  7：p q r s
 *  8：t u v
 *  9：w x y z
 */

#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits)
{
    /*  
        二维数组中每一行代表每种组合方案，列数代表数字个数。
        设定一个数组，每个位置代表九宫格中字母的不同位置。
        从每个数字还是找起，找到对应数组中的多个字母。
        循环次数为当前数字所代表的字母个数，分别保存到part数组中。
        res的长度为数字个数，part的长度为数字所代表的字母个数。
        temp代表当前组合，最终加入到res中。
    */

    vector<string> res;
    if (digits.empty())
        return res;
    res.push_back("");
    string list[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = digits.length();
    for (int i = 0; i < len; i++)
    {
        int num = digits[i] - '0';
        if (num < 0 || num > 9)
            break;
        string part = list[num];
        if (part.empty())
            continue;
        vector<string> temp;
        for (int j = 0; j < res.size(); j++)
        {
            for (int k = 0; k < part.size(); k++)
                temp.push_back(res[j] + part[k]);//temp 保存顺序： a b c
                                                 //ad ae af bd be bf cd ce cf
        }
        res.swap(temp);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string digits = "29";
    vector<string> letters = letterCombinations(digits);
    for (int i = 0; i < letters.size(); i++)
    {
        cout << letters[i] << " ";
    }
    return 0;
}
