/** 问题描述：
 *  一个信息包含 26 个英文字母，它被编码成了数字 1-26
 *  给定一个非空字符串，仅包含数字，判断这个数字能被解码成多少种字母。
 */

#include <iostream>
#include <string>

using namespace std;

// void numDecodings(string s, int& res, int pos)
// {
//     if (pos == s.length())
//     {
//         res++;
//         return ;
//     }

//     if (s[pos] == '0')
//         return ;
//     numDecodings(s, res, pos+1);
//     if (pos < s.length()-1 && stoi(s.substr(pos, 2))<=26)
//         numDecodings(s, res, pos+2);
// }

int numDecodings(string s)
{
    /*
        回溯法。
        每次位置往下走一个。
        单个弄完之后，如果往下走两个，小于26，则就走两个位置。
        当位置大于长度时，确定完成一个结果。
    */

    // if (s.length() == 0)
    //     return 0;
    // int res = 0;
    // numDecodings(s, res, 0);
    // return res;

    /*
        动态规划。
        将最后一个置为1。
        如果两位小于26，则dp等于后两位相加，否则等于后一位相加。
        第一位即为结果。
    */
   
    int len = s.length();
    if (len == 0)
        return 0;
    
    int dp[len+1];
    dp[len] = 1;

    for (int i = len-1; i >= 0; i--)
    {
        if (s[i] == '0')
            dp[i] = 0;
        else
        {
            dp[i] = (i<len-1 && (s[i]=='1' || (s[i]=='2'&&s[i+1]<='6'))) ? dp[i+1]+dp[i+2] : dp[i+1];
        }
    }
    return dp[0];
}

int main(int argc, char const *argv[])
{
    string s = "1265";
    cout << numDecodings(s);
    return 0;
}
