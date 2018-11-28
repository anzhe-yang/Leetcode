/** 问题描述：
 *  罗马数字由七个符号表示：I V X L C D M。
 *  给定一个罗马数字，将它转化为整数。
 *  假设输入被限制在 1 到 3999。
 *  "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
    "", "M", "MM", "MMM", "MMMM"
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 10, 20, 30, 40, 50, 60, 70, 80, 90,
    0, 100, 200, 300, 400, 500, 600, 700, 800, 900,
    0, 1000, 2000, 3000, 4000
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    /*
        将每个罗马字符所代表的数字保存在map中。
        如果当前罗马字符比前一个小，证明不能从此字符开始算，直到比前一个字符大才行。
        数字就是当前罗马字符的数字减去前一个罗马字符数字乘2。
    */

    int number = 0;
    unordered_map<char, int> romanToNum{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < s.length(); i++)
    {
        int temp = romanToNum[s[i]];
        if (romanToNum[s[i]] > romanToNum[s[i-1]])
            number = number + temp - 2*romanToNum[s[i-1]];//若使VI，则加上5之后要减去两个1
        else
            number += temp;
    }
    return number;
}

int main(int argc, char const *argv[])
{
    string s = "VI";
    cout << romanToInt(s);
    return 0;
}
