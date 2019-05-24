/** 问题描述：
 *  给定一个输入字符串，挨个翻转每个单词。
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseWords(string s)
{
    /*
        将每个单词保存在temp变量里。
        定义一个栈，当遇到空格时，将temp压入栈。
        最后在将栈挨个弹出到res里，中间加空格。
    */
   
    if (s.length() == 0)
        return "";
    string res = "";
    int len = s.length();
    string temp = "";
    stack<string> sstring;
    for (int i = 0; i <= len; i++)
    {
        if (s[i] == '\0')
        {
            if (!temp.empty())
                sstring.push(temp);
        }
        else if (s[i] == ' ')
        {
            if (!temp.empty())
            {
                sstring.push(temp);
                temp.clear();
            }
            continue;
        }
        else
        {
            temp += s[i];
        }
    }
    while (!sstring.empty())
    {
        res += sstring.top();
        res += ' ';
        sstring.pop();
    }
    if (!res.empty())
        res.erase(res.length()-1);
    return res;
}

int main(int argc, char const *argv[])
{
    // string s = "the sky is blue";
    string s = "  ";
    cout << reverseWords(s);
    return 0;
}
