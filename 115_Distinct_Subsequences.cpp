/** 问题描述：
 *  给定一个字符串 S 和一个字符串 T ，计算使用 S 中的子串生成 T 有多少种方法。
 *  一个字符串的子序列是没有扰乱元素相关位置，仅通过删除一些元素来形成的新的字符串。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t)
{
    /*
        DP算法。
        标准字符串t为行，待比较字符串s为列。
        dp的第一行都为1，即空字符串都代表非空字符串的一个元素，但仅代表一个。
        dp的第一列都为0，因为空字符串不可能包含非空字符串。
        之后一列代表s中每个元素是否与这一列的t元素相等，相等则加1，不相等则依旧是前一个元素值。
        之后每列都进行比较，相等则不光要加左元素的值，还要加上左上元素的值，即匹配之前元素所得到的方法数目。
    */

    // if (s.length() < t.length())
    //     return 0;
    
    // vector<vector<int>> dp(t.length()+1, vector<int>(s.length()+1, 0));
    // for (int j = 0; j < s.length(); j++)
    // {
    //     dp[0][j] = 1;
    // }
    // for (int i = 1; i <= t.length(); i++)
    // {
    //     for (int j = 1; j <= s.length(); j++)
    //     {
    //         if (t[i-1] == s[j-1])
    //         {
    //             dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i][j-1];
    //         }
    //     }
    // }
    // return dp[t.length()][s.length()];

    /*
        题目修改，需要将int转换为long型。
        将二维dp转换为一维dp。
        列从后往前判断，如果元素相等，则当前dp等于当前元素加上前一元素的值。
    */

    int m = s.length(), n = t.length();
    vector<long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= m; i++) 
    {
        for(int j = n; j >= 1; j--) 
        {
            if(s[i-1] == t[j-1]) 
            {
                dp[j] += dp[j - 1];
            } 
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    string s = "rabbbit";
    string t = "rabbit";
    cout << numDistinct(s, t);
    return 0;
}
