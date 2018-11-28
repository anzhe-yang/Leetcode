/** 问题描述：
 *  给定一个字符串 s 和一个多个单词的字符串数组 words ，所有的单词长度相同。
 *  从 s 中找到所有的单词串联之后的子字符串开始的索引，每个子字符串必须包含所有单词，单词顺序无所谓，之间没有插入任何字符。
 *  不关心返回的顺序。
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
    int slen = s.size();
    int wlen = words.size();
    int each_len = words[0].size();
    vector<int> res;

    if (slen <= 0 || wlen <= 0)
        return res;

    unordered_map<string, int> dict;
    for (int i = 0; i < wlen; i++)
        dict[words[i]]++;//把words中每个单词保存在map里，并且每个单词都有一个序号，map里保存（单词，序号）
    
    for (int i = 0; i < each_len; i++)
    {
        int left = i, count = 0;//left代表开始索引
        unordered_map<string, int> tdict;
        for (int j = i; j <= slen-each_len; j+=each_len)//从i开始，each_len为步长开始搜索
        {
            string str = s.substr(j, each_len);//从s的第j位置截取each_len长度的字符串
            if (dict.count(str))//从字典搜索是否有这个截取后的字符串，有则1
            {
                tdict[str]++;//部署在新的map里，并将序号+1
                if (tdict[str] <= dict[str])//如果单词顺序与words里一致
                    count++;
                else//如果单词顺序不一致
                {
                    while (tdict[str] > dict[str])
                    {
                        string str1 = s.substr(left, each_len);
                        tdict[str1]--;//重新截取str1，部署在字典里，序号-1
                        if (tdict[str1] < dict[str1])
                            count--;//若顺序一致了，则count--
                        left += each_len;//开始下一个单词循环
                    }
                }

                if (count == wlen)//若单词循环完了
                {
                    res.push_back(left);//保存索引
                    tdict[s.substr(left, each_len)]--;//保存第一个单词进tdict，序号-1
                    count--;
                    left += each_len;
                }
            }
            else
            {
                tdict.clear();
                count = 0;
                left = j + each_len;//说明此索引没有匹配的单词
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    string s = "barfoothefoobarman";
    string word[] = {"foo", "bar"};
    vector<string> words(word, word+2);
    vector<int> index = findSubstring(s, words);
    for (int i = 0; i < index.size(); i++)
        cout << index[i] << " ";
    return 0;
}
