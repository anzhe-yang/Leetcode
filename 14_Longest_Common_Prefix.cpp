/** 问题描述：
 *  编写一个函数来查找字符串数组中最长的公共前缀字符串。
 *  如果没有公共前缀，则返回空字符串。
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    /*
        双循环，i代表第一个字符串的长度，j代表字符串的个数。
        将每个字符串中的字母与第一个字符串中对应位置字母进行比较，等于则加，不等于则返回。
    */
   
    int len = strs.size();
    string longCommon = "";

    for (int i = 0; i < strs[0].size(); i++)
    {   
        int j = 1;
        for (; j<len && strs[j].size()>i; j++)
            if (strs[j][i] != strs[0][i])
                return longCommon;
        if (j == len)
            longCommon += strs[0][i];
    }
    return longCommon;
}

int main(int argc, char const *argv[])
{
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    cout << longestCommonPrefix(strs);
    return 0;
}
