/** 问题描述：
 *  给定一个二叉树，返回其最浅的深度。
 *  最浅的深度是从根节点到最近的叶节点的距离。
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

int minDepth(TreeNode* root)
{
    /*
        如果左节点为NULL，找右节点的最浅深度+1。
        如果右节点为NULL，找左节点的最浅深度+1。
        如果都不为NULL，返回左右最浅的深度+1。
    */
   
    if (!root)
        return 0;

    if (!root->left)
        return 1+minDepth(root->right);
    
    if (!root->right)
        return 1+minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
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

    cout << minDepth(t1);
    return 0;
}
