/** 问题描述：
 *  给定一个二叉树，返回其最大深度。
 *  最大深度为从根节点到最远叶节点的节点数目。
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

int maxDepth(TreeNode* root)
{
    /*
        迭代法。
        根节点为1个距离，然后循环每个left和right，找到最长的。
    */
   
    if (!root)
        return 0;
    int res = 1 + max(maxDepth(root->left), maxDepth(root->right));
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;

    cout << maxDepth(t1);
    return 0;
}
