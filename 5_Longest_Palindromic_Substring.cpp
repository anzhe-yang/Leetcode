/** 问题描述：
 *  给定一个字符串，找到其中最长的回文子串。
 *  假设字符串最长的长度为1000。
 */

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s)
{
    /*
        根据回文的特点，找中心点，其中i为中心点，向外扩充寻找最大回文字符串
    */

    int len = s.length();
    string palindstring = "";
    if (len < 2)
        return s;

    for (int i = 0; i < len; i++)
    {
        int left = i;
        int right = i;
        while (left > 0 && right < len-1 && s[left-1] == s[right+1])
        {
            left--;
            right++;
        }
        if (right-left+1 > palindstring.size())
        {
            palindstring = s.substr(left, right-left+1);
        }
    }
    for (int j = 0; j < len-1; j++)
    {
        if (s[j] == s[j+1])
        {
            int left = j;
            int right = j+1;
            while (left > 0 && right < len-1 && s[left-1] == s[right+1])
            {
                left--;
                right++;
            }
            if (right-left+1 > palindstring.size())
            {
                palindstring = s.substr(left, right-left+1);
            }
        }
    }
    return palindstring;


    /*
        从两边开始找。
    */
   
    // int len = s.length();
    // string palindstring = "";
    // if (len < 2)
    //     return s;
    // int max_size = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     for (int j = i+1; j <= len; j++)
    //     {
    //         string temp = s.substr(i, j-i);

    //         auto size = temp.size();
    //         auto start = temp.begin();
    //         auto end = temp.rbegin();
    //         int flag = 0;

    //         for (auto k = 0; k != size/2; ++k, ++start, ++end)
    //         {
    //             if (*start != *end)
    //                 flag = 1;
    //         }

    //         if (flag == 0)
    //         {
    //             if (max_size < temp.size())
    //             {
    //                 palindstring = temp;
    //                 max_size = temp.size();
    //             }
    //         }
    //     }
    // }
    return palindstring;
}

int main(int argc, char const *argv[])
{
    string s = {"sbcccbad"};
    string palind = longestPalindrome(s);
    cout << palind;
    return 0;
}
