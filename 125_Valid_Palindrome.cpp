/** 问题描述：
 *  给定一个字符串，确定它是否是回文字符串，只考虑字母字符并忽略大小写。
 *  假设空字符串也是有效的回文字符串。
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s)
{
    /*
        isalnum判断当前字符是否是数字或者字母，如果不是返回零。
        tolower将当前字符转化为小写，toupper转化为大写。
        首先定义两个位置指针，分别找到字母或者数字的位置，比较是否相等。
    */
   
    if (s.length() == 0)
        return true;
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        while (start < end && !isalnum(s[start]))
            start++;
        while (start < end && !isalnum(s[end]))
            end--;
        if (tolower(s[start++]) != tolower(s[end--]))
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s = "A man, a plan, a canal: Panama";
    cout << boolalpha << isPalindrome(s);
    return 0;
}
