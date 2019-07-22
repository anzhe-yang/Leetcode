/** 问题描述：
 *  所有的 DNA 由 A、C、G、T 的核苷酸组成。
 *  编写一个函数来寻找所有出现超过一次的 10 字母长度的序列。
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    /*
        用一个哈希表保存序列和出现的次数，每截取一个序列判断它是否存在过。
        存在过就+1，没有就保存。
        最后返回个数超过1的所有序列。
    */
    vector<string> res;
    int len = s.length();
    if (len < 10)
    {
        return res;
    }

    unordered_map<string, int> strmap;
    for (int i = 0; i < len; i++)
    {
        if (i + 10 <= len)
        {
            string tmps = s.substr(i, 10);
            if (strmap.find(tmps) == strmap.end())
                strmap.insert(make_pair(tmps, 1));
            else
                strmap.at(tmps) += 1;
        }
    }

    for (auto& str : strmap)
    {
        if (str.second > 1)
        {
            res.push_back(str.first);
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for (string echs : res)
    {
        cout << echs << endl;
    }
    return 0;
}
