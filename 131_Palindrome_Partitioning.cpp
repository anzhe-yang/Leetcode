/** 问题描述：
 *  给定一个字符串，将其进行分开，使每个子串都是回文字符串。
 *  返回所有可能的子串。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPartition(string s, int left, int right)
{
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

void findPartition(string &s, vector<vector<string>> &res, vector<string> &temp, int pos, int len)
{
    if (pos == len)
    {
        res.push_back(temp);
        return ;
    }
    for (int i = pos; i < len; i++)
    {
        if (isPartition(s, pos, i))
        {
            temp.push_back(s.substr(pos, i-pos+1));
            findPartition(s, res, temp, i+1, len);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    /*
        回溯法。
        分别判断每个子串是否满足回文。
    */
   
    vector<vector<string>> res;
    if (s.empty())
        return res;
    int len = s.length();
    vector<string> temp;
    findPartition(s, res, temp, 0, len);
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "aab";
    vector<vector<string>> res = partition(s);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
