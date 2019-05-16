/** 问题描述：
 *  数据集 [1, 2, 3, ..., n] 包含一整个 n! 个独立的排列组合。
 *  按顺序排列并标记所有组合，当 n 为3时：
 *  123
 *  132
 *  213
 *  231
 *  312
 *  321
 *  给定 n 和 k ，返回第 k 个组合序列。
 *  假设 n 的范围为1-9。
 */

#include <iostream>
#include <string>

using namespace std;

string getPermutation(int n, int k)
{
    /*
        初始化字符串res为0。
        求字符串的排列组合数量。
        初始化res为1234...。
        对于n个排列组合问题，有n!个组合，有n-1!个以1开始的组合，n-1!个以2开始的组合，等等。
        之后在1开头的情况下，有(n-2)!个以其余数中最小的数2开始的组合。
        之后找到第k个排列组合。
    */
    string res(n, '0');
    int num_s = 1;
    for (int i = 1; i <= n; i++)
    {
        num_s *= i;// n!个
        res[i-1] += i;//res为1234...n
    }

    k--;
    int j = 1;
    //左边部分是部分排列好的组合，右边部分是剩下的字符
    for (int i = 0; i < n; i++)
    {
        num_s /= n-i;//n! -> (n-1)! -> (n-2)! -> ...
        j = i + k / num_s;//找到该置于res[i]的位置的字符索引
        char c = res[j];
        for (; j > i; j--)//开始调整右边部分，移动字符c
            res[j] = res[j-1];//调换后面每一个字符
        k %= num_s;//k在剩下的(n-i)!组合中的第几个
        res[i] = c;//将c置于res[i]，完成左边排列好的部分
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n = 3, k = 5;
    cout << getPermutation(n, k);
    return 0;
}
