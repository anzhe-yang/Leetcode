/** 问题描述：
 *  给定两个单词和一个字典集，找到从第一个单词变换到第二个单词所需的最短的转换长度。
 *  一次只能转换一个字母。
 *  每个转换词都应在字典集中存在，第一个词不是字典集的词，而第二个是。
 *  如果无法转换则返回零。
 *  所有的单词都有相同的长度，仅包含小写字母，并没有重复的单词。
 *  假设两个单词非空，并且不相同。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    /*
        广度优先遍历搜索。
        建立路径集合paths，并将beginWord插入进去。
        只要路径集合不为空，进行while循环。
        逐个单词查找，将每个单词取出放入word变量中。
        从字典集中清除word，防止之后重复循环。
        将word字符串中每个字符进行变换，查找是否某一次变换后结果在wordList字典集中可以找到。
        找到则将其插入paths中，最小路径+1。
        没找到则取出当前word，也就是paths中这个单词不应该在路径中，因为它转化不了下一个单词，直到队列paths为空。
        如果发现转化后的word就是endWord，则循环结束，返回结果。
    */
   
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> paths;
    paths.push(beginWord);
    int minLadder = 1;
    while (!paths.empty())
    {
        int n = paths.size();
        for (int i = 0; i < n; i++)
        {
            string word = paths.front();
            paths.pop();
            if (word == endWord)
                return minLadder;
            dict.erase(word);
            for (int j = 0; j < word.length(); j++)
            {
                char c = word[j];
                for (char k = 'a'; k <= 'z'; k++)
                {
                    word[j] = k;
                    if (dict.find(word) != dict.end())
                    {
                        paths.push(word);
                    }
                }
                word[j] = c;
            }
        }
        minLadder++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string beginWord = "hot";
    string endWord = "dog";
    vector<string> wordList{"hot", "dog"};
    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}