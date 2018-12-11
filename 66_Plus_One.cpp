/** 问题描述：
 *  给定一个非空数字数组，代表一个非负整数，将这个整数加 1 。
 *  存储数字的方法是使得最高有效数字位于列表的开头，并且数组中每个元素仅包含单个数字。
 *  假设数组中第一个数不为零，除非只有数字零。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    /*
        从最后一位开始加1。
        如果有进位，则继续循环。
        如果没有进位，则退出循环。
        如果退出循环后进位符号为0，说明进位处理完毕，返回。
        如果不为0，则说明第一位也进位了，产生新数组，第一位为1，其他位一样，返回。
    */
   
    int len = digits.size();
    int sign = 0;
    for (int i = len-1; i >= 0; i--)
    {
        digits[i] = digits[i] + 1;
        if (digits[i] > 9)
        {
            digits[i] = digits[i] - 10;
            sign = 1;
            continue;
        }
        else
        {
            sign = 0;
            break;
        }
    }

    if (sign == 1)
    {
        vector<int> res(len+1, 0);
        res[0] = 1;
        for (int i = 1; i < len+1; i++)
        {
            res[i] = digits[i-1];
        }
        return res;
    }
    return digits;
}

int main(int argc, char const *argv[])
{
    vector<int> digits{4, 9, 9};
    vector<int> res = plusOne(digits);
    for (int s : res)
        cout << s << " ";    
    return 0;
}
