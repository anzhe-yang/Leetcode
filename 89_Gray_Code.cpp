/** 问题描述：
 *  格雷码是二进制数字系统，两个连续的值只有一位不同。
 *  给定格雷码的总位数为非负整数，输出所有格雷码序列。一个格雷码序列必须从零开始。
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n)
{
    // vector<int> res;//格雷码序列大小为2^n
    // if (n == 0)
    // {
    //     res.push_back(0);
    //     return res;
    // }

    /*
        计算n的格雷序列，通过计算n-1的格雷序列得出。
        如n=2的格雷序列为  00, 01, 11, 10
        则n=3的格雷序列为 000,001,011,010   110,111,101,100
        前半边为上方序列在最前面加一位0，后半边为前半边的镜像序列将第一位改为1。
        算法通过将前一个格雷序列的每一个序列与将1右移i位取或运算，即得到后半边的序列。
        前半边的序列即位前一个n的格雷序列，所以算法在每个i循环中增加后半序列的数字。
    */

    vector<int> res(1, 0);
    for (int i = 0; i < n; i++)
    {
        int size = res.size();
        for (int j = size-1; j >= 0; j--)
        {
            res.push_back(res[j] | 1<<i);//|为按位或运算
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 3;
    vector<int> res = grayCode(n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
