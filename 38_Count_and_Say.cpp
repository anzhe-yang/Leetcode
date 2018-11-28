/** 问题描述：
 *  报数序列是一个整数序列，按照其中的整数的顺序进行报数，从而得到下一个数。
 *  前五项为：
 *  1. 1
 *  2. 11
 *  3. 21
 *  4. 1211
 *  5. 111221
 *  1 被读作 一个一 即 11
 *  11 被读作 两个一 即 21
 *  21 被读作 一个二一个一 即1211
 *  给定一个小于等于30的正整数，输出报数序列的第 n 项。
 *  整数顺序将表示为一个字符串。
 */

#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n)
{
    /*
        fro表示前一个序列。
        cur表示当前序列。
        count计算整数重复个数。
        每次将fro置为cur，将cur清零。
        返回fro。
    */
   
    string fro = "1", cur = "";
    int i = 2;
    while (i <= n)
    {
        int len = fro.length();
        char temp = fro[0];
        int count = 1;
        for (int j = 1; j <= len; j++)
        {
            if (fro[j] == temp)
                count++;
            else
            {
                cur += to_string(count) + temp;
                count = 1;
            }
            temp = fro[j];
        }
        fro = cur;
        cur = "";
        i++;
    }
    return fro;
}

int main(int argc, char const *argv[])
{
    int n = 6;
    cout << countAndSay(n);
    return 0;
}
