/** 问题描述：
 *  给定两个单词和一个字典集，找到从第一个单词变换到第二个单词所需的最短的转换序列。
 *  一次只能转换一个字母。
 *  每个转换词都应在字典集中存在，第一个词不是字典集的词，而第二个是。
 *  如果无法转换则返回空。
 *  所有的单词都有相同的长度，仅包含小写字母，并没有重复的单词。
 *  假设两个单词非空，并且不相同。
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
// {
//     vector<vector<string>> res;
//     int len = beginWord.length();

//     return res;
// }
// vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList)
// {
//     vector<vector<string>> res;
//     queue<vector<string>> paths;
//     wordList.insert(endWord);
//     paths.push({beginWord});
//     int level = 1;
//     int minLevel = INT_MAX;

//     unordered_set<string> visited;
//     while (!paths.empty())
//     {
//         vector<string> path = paths.front();
//         paths.pop();
//         if (path.size() > level)
//         {
//             for (string w : visited)
//             {
//                 wordList.erase(w);
//             }
//             visited.clear();
//             if (path.size() > minLevel)
//                 break;
//             else
//                 level = path.size();
//         }
//         string last = path.back();
//         for (int i = 0; i < last.size(); i++)
//         {
//             string news = last;
//             for (char c = 'a'; c <= 'z'; c++)
//             {
//                 news[i] = c;
//                 if (wordList.find(news) != wordList.end())
//                 {
//                     vector<string> newPath = path;
//                     newPath.push_back(news);
//                     visited.insert(news);
//                     if (news == endWord)
//                     {
//                         minLevel = level;
//                         res.push_back(newPath);
//                     }
//                     else
//                     {
//                         paths.push(newPath);
//                     }  
//                 }
//             }
//         }
//     }
//     return res;
// }

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    /*
        完全不会。
        用标准BFS广度优先遍历法。
        建立一个路径集合paths，保存所有路径。
        路径的起始点为beginWord。
        定义两个变量，level保存当前路径长度，minLevel保存最短路径长度，当level大于minLevel就抛弃。
        定义一个set变量visited，记录在这条路径上已经循环过的节点词，这些词在之后的路径中不会再循环了，需要从wordList（也就是dict）中删除。记录已经循环过的路径中的词。
        开始BFS：
        循环遍历paths中的内容，如果该路径大于level，说明删除visited之后的wordList已经有部分词存入路径中了，如果在路径中重复出现，肯定不是最短路径，删除它。
        然后做清空操作，并查看是否大于minLevel。
        然后取出当前路径的最后一个词，对每个字母进行替换并在wordList中查找是否存在替换后的新词。
        如果存在，则加入visited中，并在新路径上newPath加入这一新词形成新的路径。
        如果这个新词就是endWord，则形成一条完整路径，加入res中，并更新minLevel。
        如果不是endWord，则将新路径newPath加入paths队列中继续循环。
    */

    vector<vector<string>> res;
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return res;

    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<vector<string>> paths;
    dict.insert(endWord);
    paths.push({beginWord});
    int level = 1;
    int minLevel = INT_MAX;

    unordered_set<string> visited;
    while (!paths.empty())
    {
        vector<string> path = paths.front();
        paths.pop();
        if (path.size() > level)
        {
            for (string w : visited)
            {
                // wordList.erase(find(wordList.begin(), wordList.end(), w));
                dict.erase(w);
            }
            visited.clear();
            if (path.size() > minLevel)
                break;
            else
                level = path.size();
        }
        string last = path.back();
        for (int i = 0; i < last.size(); i++)
        {
            string news = last;
            for (char c = 'a'; c <= 'z'; c++)
            {
                news[i] = c;
                // if (find(wordList.begin(), wordList.end(), news) != wordList.end())
                if (dict.find(news) != dict.end())
                {
                    vector<string> newPath = path;
                    newPath.push_back(news);
                    visited.insert(news);
                    if (news == endWord)
                    {
                        minLevel = level;
                        res.push_back(newPath);
                    }
                    else
                    {
                        paths.push(newPath);
                    }  
                }
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    // unordered_set<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);
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
