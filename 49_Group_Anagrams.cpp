/** 问题描述：
 *  给定一组字符串，将所有具有同样字符的字符串组合在一起。
 *  假设所有输入都是小写的字母。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    /*
        定义一个哈希表，存储strs中每个元素排序后的字符串，和排序后是相同字符串的原字符串。
        对哈希表中第二个元素进行排序，然后将哈希表中第一个相同的字符串压入res。
    */
   
    vector<vector<string>> res;
    unordered_map<string, vector<string>> temp;
    int i = 0;
    for (auto s : strs)
    {
        sort(s.begin(), s.end());
        temp[s].push_back(strs[i++]);
    }

    for (auto t : temp)
    {
        sort(t.second.begin(), t.second.end());
        res.push_back(t.second);
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
