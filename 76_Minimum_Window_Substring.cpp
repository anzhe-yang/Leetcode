/** 问题描述：
 *  给定两个字符串，从第一个字符串中找到最小的子字符串，使得子字符串能够完全包含第二个字符串中的所有字符。
 *  算法复杂度为 O(n) 。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string minWindow(string s, string t)
{
        vector<int> maps(128,0);
        for(auto c: t) 
            maps[c]++;//将t字符串中所有字符转化为ASCII，最高128。然后如果出现一次，在对应位置加1。则maps中的元素代表了t字符串中所有字符出现的次数和位置
                      //如t为ABC，则maps[65]=1, maps[66]=1, maps[67]=1
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while(end < s.size())//仅遍历一次s字符串，找到所有符合规则的子字符串
        {
            if(maps[s[end++]]-- > 0)//判断s中当前end位置是否包含t中的字符，包含则将maps对应位置减去1
                counter--;
            while(counter == 0)//当t中所有字符都处理完毕时
            {
                if(end-begin < d)//d是代表了符合规则字符串的最小长度
                    d = end - (head=begin);
                if(maps[s[begin++]]++ >= 0)//如果maps中s[0]这个字符位置还大于等于0，则认为没弄完，这个字符没包含完毕，t中可能包含2个这个字符
                    counter++;//继续匹配
            }  
        }
        return d==INT_MAX ? "" : s.substr(head, d);//d代表了最优子字符串的长度，head代表了其在s中的起始位置
}

int main(int argc, char const *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}
