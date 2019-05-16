/** 问题描述：
 *  给定一个非空字符串 s 和一个包含非空英文的字典。
 *  给 s 中加入空格构成句子，使得分隔开的每个单词都是一个合法的字典中的单词。
 *  返回所有可能的句子。
 *  分隔过程中，字典中的单词可以重复使用。
 *  假设字典中不包含重复的单词。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> map;

vector<string> wordBreak(string s, vector<string>& wordDict)
{
    /*
        先找最后一个词，就是s中从后往前走，找到某个词属于字典，将它标记为last。
        然后通过回溯法，将剩下的s置为下一个要处理的s，再从后往前找，将所有可能的结果保存在remainRes，代表了剩下的s所得到的结果。
        最后再加上之前last，压入res。
    */

    // int len = s.length();
    // vector<string> res;
    // if (wordDict.size() == 0)
    //     return res;
    
    // unordered_set<string> dict(wordDict.begin(), wordDict.end());
    // for (int i = len-1; i >= 0; i--)
    // {
    //     string last = s.substr(i, len-i);
    //     if (dict.find(last) != dict.end())
    //     {
    //         if (i == 0)
    //         {
    //             res.push_back(last);
    //         }
    //         else
    //         {
    //             string remain = s.substr(0, i);
    //             vector<string> remainRes = wordBreak(remain, wordDict);
    //             if (remainRes.size() != 0)
    //             {
    //                 for (string r : remainRes)
    //                 {
    //                     res.push_back(r + " " + last);
    //                 }
    //             }
    //         }
    //     }
    // }
    // return res;

    /*
        先找第一个词word。
        然后通过一个map变量，查询这个词是否已经计算过。
    */

    if (map.find(s) != map.end())
        return map[s];
    vector<string> res;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    if (dict.find(s) != dict.end())
    {
        res.push_back(s);
    }
    for (int i = 1; i < s.length(); i++)
    {
        string word = s.substr(i);
        if (dict.find(word) != dict.end())
        {
            string remain = s.substr(0, i);
            vector<string> remainRes = wordBreak(remain, wordDict);
            for (string r : remainRes)
            {
                res.push_back(r + " " + word);
            }
        }
    }
    map[s] = res;
    return res;
}

int main(int argc, char const *argv[])
{
    string s = "catsanddog";
    vector<string> wordDict{
        "cat",
        "cats",
        "and",
        "sand",
        "dog"
    };
    vector<string> res = wordBreak(s, wordDict);
    for (string s : res)
    {
        cout << s << endl;
    }
    return 0;
}
