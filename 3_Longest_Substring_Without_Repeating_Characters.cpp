/** 问题描述：
 *  给定一个字符串，返回其中最长无重复字母的子字符串的长度。
 */

#include <iostream>
#include <string>
#include <hash_map>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    /*
        用map找出重复字符。
    */
   
    int len = 0;
    map<char, int> map_string;
    for (int i = 0, j = 0; j < s.length(); j++)
    {
        if (map_string.count(s[j]))
        {
            i = max(map_string.find(s[j])->second, i);
            map_string.find(s[j])->second = j + 1;
        }
        else
        {
            map_string.insert(pair<char, int>(s[j], j+1));
        }
        len = max(len, j-i+1);//j+1 表示字符串中字母的个数 i 表示其中重复字母的个数
    }
    return len;
}

int main(int argc, char const *argv[])
{
    string s = "bbbbb";
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}