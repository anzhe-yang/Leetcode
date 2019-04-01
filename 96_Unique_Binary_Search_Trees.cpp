/** 问题描述：
 *  给定一个整数 n ，返回所有不同的二叉搜索树的个数。
 */

#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    /*
        二叉树以第i个节点为根节点，则1..i-1为左子树，i+1...n为右子树。
        那么以每个i为节点，就可以构造出所有不同的二叉树。
        定义一个动态规划数组res保存当前长度为n的时候，二叉树的个数。
        0个节点和1个节点都只有一个二叉树。
        定义另一个公式F(i,n)为以i为根节点，有n个数字的二叉树个数。
        所以当前n个节点拥有的二叉树个数就是F(1,n)+F(2,n)+...F(n,n)。
        而以i为根节点时，左字数又等于长度为i-1的二叉树个数，即为res[i-1]，右子树雷同。
        所以F(i,n)=G(i-1)*G(n-i)。
        将两个公式联合起来即为算法中的公式。
    */

    int res[n+1];
    res[0] = 1, res[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        res[i] = 0;//累加前要清零
        for (int j = 1; j <= i; j++)
        {
            res[i] += res[j-1] * res[i-j];
        }
    }
    return res[n];
}

int main(int argc, char const *argv[])
{
    int n = 3;
    cout << numTrees(n);
    return 0;
}