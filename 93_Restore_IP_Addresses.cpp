/** 问题描述：
 *  给定一个字符串仅包含数字，将它们进行重新分配，返回一个有效的IP地址。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s)
{
    if (s.length()>3 || s.length()==0 || (s[0]=='0'&&s.length()>1) || stoi(s)>255)
        return false;
    return true;
}

vector<string> restoreIpAddresses(string s)
{
    /*
        暴力解法。
        分成4段字符串，循环挨个分配。
        是否符合规则函数中，字符串长度大于3、长度为0、首字母为0但长度不为0、整体数字大于255都不符合规则。
        当4个字符串都符合，则并入res。
    */
   
    vector<string> res;
    int len = s.length();
    for (int i = 1; i < 4 && i < len-2; i++)
    {
        for (int j = i+1; j < i+4 && j < len-1; j++)
        {
            for (int k = j+1; k < j+4 && k < len; k++)
            {
                string s1 = s.substr(0, i-0);
                string s2 = s.substr(i, j-i);
                string s3 = s.substr(j, k-j);
                string s4 = s.substr(k, len-k);
                if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                {
                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "25525511135";
    vector<string> res = restoreIpAddresses(s);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
