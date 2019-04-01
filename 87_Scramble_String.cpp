/** 问题描述：
 *  给定一个字符串 s1 ，将它用二叉树分成两个非空子字符串。
 *  将形成的二叉树中选择任意非叶节点，并交换其两个子节点，形成新的字符串，将此字符串称作乱字符串。
 *  给定两个字符串 s1 s2 ，判断 s2 是否是 s1 的乱字符串。
 */

#include <iostream>
#include <string>

using namespace std;

bool isScramble(string s1, string s2)
{
    /*
        回溯法。
        首先判断两个字符长度是否相等。
        通过建立一个字母表，当含有这个字母则在对应位置加一，另一个含有则减一，判断两个字符串含有的字符是否相等。
        之后逐次判断前i个子字符串是否相等，不相等则判断前i个和后i个字符是否相等。
        循环判断，都相等则返回true。
    */
   
    if (s1.length() != s2.length())
        return false;

    if (s1 == s2)
        return true;
    
    int len = s1.length();
    int cpar[26] = {0};
    for (int i = 0; i < len; i++)
    {
        cpar[s1[i]-'a']++;
        cpar[s2[i]-'a']--;
    }//判断两个字符串是否包含完全一样的字母
    for (int s : cpar)
    {
        if (s != 0)
            return false;
    }//如果有不一样则返回false
    
    for (int i = 1; i < len; i++)
    {
        if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
            return true;//从第i个元素分开，分别判断两个字符串是否相等，从1开始循环判断
        if (isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
            return true;//如果前面不相等，判断第一个字符串的前i个字符和第二个字符串的后i个字符是否相等，和第一个字符串第i个字符之后和第二个字符串前len-i个字符是否相等
                        //检查s1[0...i-1]和s2[len-i...len-1]是否相等，和s1[i...len-1]和s2[0...len-i]是否相等
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s1 = "great";
    string s2 = "rgeat";
    cout << s1.substr(0, 1) << " " << s2.substr(5-1) << endl;
    cout << s1.substr(1) << " " << s2.substr(0, 5-1) << endl;
    cout << boolalpha << isScramble(s1, s2);
    return 0;
}
