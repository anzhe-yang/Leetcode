/** 问题描述：
 *  给定三个字符串 s1 s2 s3 ，判断 s3 是否由 s1 和 s2 交织组成。
 */

#include <iostream>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    /*
        DP算法。
        判断当前位置的s1元素是否和s3对应位置的元素相等，左位置是否为true。
        判断当前位置的s2元素是否和s3对应位置的元素相等，上位置是否为true。
        https://leetcode.com/problems/interleaving-string/solution/ 这里第三个方法的图阐述的很清楚。
    */

    if (s1.length() + s2.length() != s3.length())
        return false;
    
    bool dp[s1.length()+1][s2.length()+1];
    for (int i = 0; i < s1.length()+1; i++)
    {
        for (int j = 0; j < s2.length()+1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
            else if (j == 0)
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
            else
                (dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}

int main(int argc, char const *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << boolalpha << isInterleave(s1, s2, s3);
    return 0;
}
