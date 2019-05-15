/** 问题描述：
 *  给定一个字符串，拆分其使得每个子串都是一个回文字符串。
 *  返回满足此需求的最小拆分此数。
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minCut(string s)
{
    /*
        cuts数组保存前k个字符所构成的字符串满足需求的最小拆分此数，即s[0:k-1]的最小拆分数。
        将其初始化为当前位置减1。
        检查以s[i]为中心，前j个和后j个组成的字符串是否为回文。
        奇数长度判断回文为s[i-j]==s[i+j]。
        偶数长度判断回文为s[i-j+1]==s[i+j]。
        当，前i+j个字符所构成的字符串是回文字符串时，cut[i+j+1]就为末尾值[i+j+1]和起始值[i-j]并加1之间的最小值。
        当for-j循环检测到一个非回文字符串(s[i-j]==s[i+j])，则停止此循环，因为不会在有以i为中心的回文字符串，改变i的值。
        返回最后一位结果。
    */

    int len = s.length();
    int cuts[len+1];
    for (int i = 0; i <= len; i++)
    {
        cuts[i] = i - 1;
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; i+j < len && i-j >= 0 && s[i-j] == s[i+j]; j++)//字符串长度为奇数
        {
            cuts[i+j+1] = min(cuts[i+j+1], cuts[i-j]+1);
        }
        for (int j = 1; i+j < len && i-j+1 >= 0 && s[i-j+1] == s[i+j]; j++)//字符串长度为偶数
        {
            cuts[i+j+1] = min(cuts[i+j+1], cuts[i-j+1]+1);
        }
    }
    return cuts[len];
}

int main(int argc, char const *argv[])
{
    string s = "aab";
    cout << minCut(s);
    return 0;
}
