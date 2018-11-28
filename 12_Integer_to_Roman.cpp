/** 问题描述：
 *  罗马数字由七个不同的符号表示：I，V，X，L，C，D，M。
 *  分别表示的数值为：1，5，10，50，100，500，1000。
 *  给定一个整数，将其转化为罗马数字。
 *  假设输入数值被限制在 1 到 3999 之间。
 */

#include <iostream>

using namespace std;

string intToRoman(int num)
{
    /*
        把罗马字符定义在一个数组中，利用公式直接得数值。
    */
   
    if (num > 3999)
        return 0;
    
    string romanPieces[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                          "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                          "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                          "", "M", "MM", "MMM", "MMMM"};
    return romanPieces[num/1000+30] + romanPieces[(num/100)%10+20] + romanPieces[(num/10)%10+10] + romanPieces[num%10];
}

int main(int argc, char const *argv[])
{
    int num = 1994;
    cout << intToRoman(num);
    return 0;
}
