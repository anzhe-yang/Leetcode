/** 问题描述：
 *  给定一个只包含数字 0-9 的二叉树，每个从根到叶节点的路径代表一个数字。
 *  例如根到叶节点路径为 1->2->3 ，代表数字 123 。
 *  返回整体每个路径的数字总和。
 */

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumNodes(TreeNode *node, int sum)
{
    if (!node)
    {
        return 0;
    }
    sum = sum * 10 + node->val;
    if (!node->left && !node->right)
    {
        return sum;
    }

    return sumNodes(node->left, sum) + sumNodes(node->right, sum);    
}

void sumNodes(TreeNode *node, int &sum, int curSum)
{
    if (node)
    {
        curSum = curSum * 10 + node->val;
        if (!node->left && !node->right)
            sum += curSum;
        if (node->left)
            sumNodes(node->left, sum, curSum);
        if (node->right)
            sumNodes(node->right, sum, curSum);
    }
}

int sumNumbers(TreeNode* root)
{
    /*
        定义一个sum保存总和，将左右子树的和都加起来。
    */

    // int res = sumNodes(root, 0);
    // return res;

    /*
        定义两个变量，一个每一条路径的总和curSum，一个全部总和sum。
        迭代停止条件是当前节点为NULL，迭代条件是下一节点不为NULL。
    */
   
    int res = 0;
    sumNodes(root, res, 0);
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;

    cout << sumNumbers(t1);
    return 0;
}
