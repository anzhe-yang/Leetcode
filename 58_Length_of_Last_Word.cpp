/** 问题描述：
 *  给定一组字符串，包含大/小写字母和空格，返回最后一个字符串的长度。
 *  如果最后一个单词不存在，则返回 0。
 *  假设一个单词被定义为一个字符串序列，并且仅由非空格字符组成。
 */

#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    /*
        首先考虑字符串组是否为空。
        其次考虑字符串从最后开始，把空格都除去，直到是字符为止。
        最后从最后一个字符开始，遇到空格停止，则返回长度。
    */
   
    int len = s.length();
    if (len == 0)
        return 0;
    while (len-1 >= 0 && s[len-1] == ' ')
        len--;
    int temp = 0;
    for (int i = len-1; i >= 0; i--)
    {
        if (s[i] == ' ')
            break;
        temp++;
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    string s = "a ";
    cout << lengthOfLastWord(s);
    return 0;
}
