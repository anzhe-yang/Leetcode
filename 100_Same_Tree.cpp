/** 问题描述：
 *  给定两个二叉树，写一个函数去判断它俩是否是一样的。
 *  结构和节点值都一样才是一样的二叉树。
 */

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    /* 
        循环判断左子树，右子树，都为true才行。
        当判断到NULL，则当前子树为true。
        最后返回bool变量。
    */
   
    bool res = false;
    if (p == NULL && q == NULL)
        res = true;

    if (p && q)
    {
        if (p->val != q->val)
            return false;
        res |= isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;

    TreeNode *q1 = new TreeNode(1);
    TreeNode *q2 = new TreeNode(2);
    TreeNode *q3 = new TreeNode(3);
    q1->left = q2;
    q1->right = q3;

    cout << boolalpha << isSameTree(p1, q1);
    return 0;
}
