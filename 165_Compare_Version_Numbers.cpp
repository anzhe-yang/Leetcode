/** 问题描述：
 *  比较两个版本号数字，如果相差大于零返回 1 ，小于零返回 -1 ，否则返回 0 。
 *  假设版本号字符串是非空的，仅包含数字和 . 。
 *  其中字符 . 被用于分开数字版号。
 *  版本号不以 . 开头或者结尾，且它们不会是两个连续的 . 。
 */

#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2)
{
    /*
        遇到.的时候，+1。
        然后在区间内，将字符串转化为数字，保存起来。
        之后比较这两个数字。
    */
   
    int len1 = version1.length();
    int len2 = version2.length();
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        int temp1 = 0, temp2 = 0;
        if (version1[i] == '.')
        {
            i++;
        }
        while (i < len1 && version1[i] != '.')
        {
            temp1 = temp1 * 10 + version1[i]-'0';
            i++;
        }

        if (version2[j] == '.')
        {
            j++;
        }
        while (j < len2 && version2[j] != '.')
        {
            temp2 = temp2 * 10 + version2[j]-'0';
            j++;
        }

        if (temp1 < temp2)
        {
            return -1;
        }
        else if (temp1 > temp2)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string version1 = "1.0";
    string version2 = "1.0.0";
    cout << compareVersion(version1, version2);
    return 0;
}
