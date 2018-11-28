/** 问题描述：
 *  返回字符串 haystack 中第一次出现 needle 字符串的索引。
 *  如果没有出现则返回 -1。
 */

#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    /*
        从haystack数组的起始位置开始判断，一直到haystack数组减去needle数组的长度结束。
        因为要判断是否包含needle，最后那个长度一定是needle的长度，不能比它再少了，这一步可以减少很多运算，重要。
        然后依次判断是否匹配，一个不匹配则break。
        判断那个temp是否等于len，返回索引i。
    */
   
    if (needle.length() == 0)
        return 0;
    if (needle.length() > haystack.length())
        return -1;
    
    int len = needle.length();
    for (int i = 0; i < haystack.length()-len+1; i++)
    {
        if (haystack[i] == needle[0])
        {
            int temp = 1;
            for (; temp < len; temp++)
            {
                if (haystack[i+temp] != needle[temp])
                    break;
            }
            if (temp == len)
                return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string haystack = "mississippi";
    string needle = "issip";
    cout << strStr(haystack, needle);
    return 0;
}
