/** 问题描述：
 *  给定一个字符串和另一个模式的字符串，实现支持正则表达式 ‘.’ ‘*’ 的匹配任务。
 *  ‘.’ 匹配任意一个单独字符。
 *  ‘*’ 匹配零个或多个前一个的元素。
 *  匹配应覆盖整个字符串，而不是部分。
 */

#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
    /*  
        定义T为一个二维的代表是否匹配的数组。
        T（i，j）代表第i个字符之前和第j个字符之前是否匹配。
        返回最后一个位置是否匹配的布尔值。
        根据规则看是否匹配。
    */

    bool T[s.length()+1][p.length()+1] = {{false}};
    T[0][0] = true;
    for (int i = 0; i <= s.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (p[j-1] == '*')
                T[i][j] = T[i][j-2] || (i>0 && (s[i-1] == p[j-2] || p[j-2] == '.') && T[i-1][j]);
            else
                T[i][j] = i > 0 && T[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
        }
    }
    return T[s.length()][p.length()];
}

int main(int argc, char const *argv[])
{
    string s = "aa";
    string p = "a*";
    cout << boolalpha << isMatch(s, p);
    return 0;
}
