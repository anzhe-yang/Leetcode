/** 问题描述：
 *  给定一个字符串仅包含 ( ) [ ] { } 六种类型的字符，判断此字符串是否合法。
 *  一个合法的字符串应是：
 *  1. 必须使用相同类型的括号去抵消掉左括号。
 *  2. 括号的抵消必须按照正确的顺序。
 *  假设空的字符串也是合法的。
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
    /*
        利用栈的性质，将字符进栈，判断下一个字符是否可以抵消掉栈顶的字符，可以则出栈，否则把下一字符也压进栈。
        循环中当栈为空时，将下一字符压栈。
        最后判别栈是否为空。
    */

    int len = s.length();
    if (len % 2 != 0)
        return false;
    if (len == 0)
        return true;

    stack<char> temp;
    temp.push(s[0]);
    for (int i = 1; i < len; i++)
    {
        if (temp.empty())
            temp.push(s[i]);
        else if( (temp.top()=='(' && s[i]==')') || (temp.top()=='[' && s[i]==']') || (temp.top()=='{' && s[i]=='}') )
            temp.pop();
        else
            temp.push(s[i]);
    }
    return (temp.empty());
}

int main(int argc, char const *argv[])
{
    string s = "()[]{[]}";
    cout << boolalpha << isValid(s);
    return 0;
}
