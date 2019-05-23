/** 问题描述：
 *  计算 Rever Polish Noation 表达式的值。
 *  合法符号有 + - * / 。
 *  每个运算单元必须是一个整数或者另外一个表达式。
 *  两个整数之间的划分应截断为零。
 *  给定的 RPN 表达式始终有效，意味着表达式总会有计算结果，并且不会有任何的除零操作。
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens)
{
    /*
        利用一个栈变量，保存每个数值。
        利用stoi将字符串转换为数值。
        当遇到符号时，弹出最顶的两个元素，进行运算，并压入顶部。
    */
   
    int num = tokens.size();
    stack<int> s;
    int i = 0;
    while (i < num)
    {
        if (tokens[i] == "+")
        {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            int temp = n1 + n2;
            s.push(temp);
        }
        else if (tokens[i] == "-")
        {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            int temp = n2 - n1;
            s.push(temp);
        }
        else if (tokens[i] == "*")
        {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            int temp = n1 * n2;
            s.push(temp);
        }
        else if (tokens[i] == "/")
        {
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            int temp = n2 / n1;
            s.push(temp);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }   
        i++;
    }
    return s.top();
}

int main(int argc, char const *argv[])
{
    vector<string> tokens{"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens);
    return 0;
}
