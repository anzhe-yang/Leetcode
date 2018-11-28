/** 问题描述：
 *  给定一个只包含括号的字符串，找到其最长的合法长度。
 *  一对合法括号的长度为2。
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
    /*
        堆栈版本，将索引压入堆栈，最后比较每一个合法括号部分的长度
    */
   
    int len = s.length();
    int maxlen = 0;
    stack<int> index;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
            index.push(i);//把索引压入堆栈
        else
        {
            if (!index.empty())
            {
                if (s[index.top()] == '(')
                    index.pop();
                else
                    index.push(i);
            }
        }
    }
    if (index.empty())//如果堆栈还为空，则都是合法括号
        maxlen = len;
    else
    {
        int a = len, b = 0;
        while (!index.empty())
        {
            b = index.top();
            index.pop();
            maxlen = max(maxlen, a-b-1);//从末尾开始提取每个合法的括号部分，得到其长度
            a = b;
        }
        maxlen = max(maxlen, a);//看哪个合法括号长度最大
    }
    return maxlen;

    /*
        从左到右遍历一遍，每个i都要判断左右括号是否相等，若右括号大于等于左括号，则清零。
        从右到左遍历一遍，每个i都要判断左右括号是否相等，若左括号大于等于右括号，则清零。
    */

    // int len = s.length();
    // int left = 0, right = 0, maxlen = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     if (s[i] == '(')
    //         left++;
    //     else
    //         right++;
    //     if (left == right)
    //         maxlen = max(maxlen, 2*right);
    //     else if (right >= left)
    //         left = right = 0;
    // }

    // left = right = 0;
    // for (int j = len-1; j >= 0; j--)
    // {
    //     if (s[j] == '(')
    //         left++;
    //     else
    //         right++;
    //     if (left == right)
    //         maxlen = max(maxlen, 2*right);
    //     else if (left >= right)
    //         left = right = 0;
    // }

    // return maxlen;
}

int main(int argc, char const *argv[])
{
    string s = "()(()()";
    cout << longestValidParentheses(s);
    return 0;
}
