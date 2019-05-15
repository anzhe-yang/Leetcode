/** 问题描述：
 *  给定一个非空字符串 s 和一个包含非空英文的字典。
 *  判断 s 是否可以被拆分成数个字符串，这些字符串都在字典中。
 *  分隔过程中，字典中的单词可以重复使用。
 *  假设字典中不包含重复的单词。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    /*
        DP法。
        定义一个bool变量，dp[i]=true代表s中以第i个元素为末尾的字符串，在字典中可以找到，长度是到前一个dp[j<i]=true的距离。
        i从1循环到len，包括len。
        第二个循环是找前一个dp[j]=true的位置，从j开始，找长度为i-j的字符串是否在字典中出现，出现则将dp[i]置为true。
        找到，则进行下一个i。
    */

    int len = s.length();
    if (wordDict.size() == 0)
        return false;
    
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(len+1, false);
    dp[0] = true;
    for (int i = 1; i <= len; i++)
    {
        for (int j = i-1; j >= 0; j--)
        {
            if (dp[j] == true)
            {
                string temp = s.substr(j, i-j);
                if (dict.find(temp) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[len];
}

int main(int argc, char const *argv[])
{
    string s = "leetcode";
    vector<string> wordDict{
        "leet",
        "code"
    };
    cout << boolalpha << wordBreak(s, wordDict);
    return 0;
}
