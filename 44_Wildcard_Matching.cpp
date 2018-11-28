/** 问题描述：
 *  给定一个字符串 s 和一个字符模式 p ，实现一个支持 '?' 和 '*' 的通配符匹配。
 *  '?' 可以匹配任何单个字符。
 *  '*' 可以匹配任意字符串（包括空字符串）。
 *  其中 s 和 p 可能为空。
 *  两个字符串完全匹配才算匹配成功。
 */

#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
    /*
        使用动态规划DP算法。
        从后往前进行匹配，相等或者p为问号时，当前元素匹配成功。
        为*号时，匹配的结果和i+1或j+1相同，只要其中一个是true就匹配成功。
        否则匹配当前元素匹配失败。
        返回temp[0][0]位置的元素。
    */
   
    int len_s = s.length();
    int len_p = p.length();
    bool temp[len_s+1][len_p+1] = {{false}};
    temp[len_s][len_p] = true;
    for (int i = len_p-1; i >= 0; i--)
    {
        if (p[i] != '*')
            break;
        else
            temp[len_s][i] = true;//p的当前元素为*时，匹配都是true
    }
    for (int i = len_s-1; i >= 0; i--)
    {
        for (int j = len_p-1; j >= 0; j--)
        {
            if (s[i] == p[j] || p[j] == '?')
                temp[i][j] = temp[i+1][j+1];
            else if (p[j] == '*')
                temp[i][j] = temp[i+1][j]||temp[i][j+1];
            else
                temp[i][j] = false;
        }
    }
    return temp[0][0];
}

int main(int argc, char const *argv[])
{
    string s = "";
    string p = "";
    cout << boolalpha << isMatch(s, p);
    return 0;
}
