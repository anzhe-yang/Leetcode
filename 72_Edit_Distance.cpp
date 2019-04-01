/** 问题描述：
 *  给定两个字符串，返回将第一个字符串转化为第二个字符串所需要的最少次数。
 *  转化方法：
 *  插入一个字符
 *  删除一个字符
 *  交换一个字符
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
    /*
        DP算法。
        替换：word1[i-1]与word2[j-1]替换。
        删除：删除word1[i-1]，使word1[0...i-2]与word2[0...j-1]相等。
        插入：将word2[j-1]插入到word1[0..i-1]之间。
    */

    int len1 = word1.length();
    int len2 = word2.length();
    vector< vector<int> > dp(len1 + 1, vector<int> (len2 + 1, 0));
    for (int i = 1; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 1; j <= len2; j++)
        dp[0][j] = j;  
    for (int i = 1; i <= len1; i++) 
    {
        for (int j = 1; j <= len2; j++) 
        {
            if (word1[i - 1] == word2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
                //              替换                        插入                删除
        }
    }
    return dp[len1][len2];
}

int main(int argc, char const *argv[])
{
    string word1 = "horse";
    string word2 = "ros";
    cout << minDistance(word1, word2);
    return 0;
}
