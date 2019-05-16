/** 问题描述：
 *  给定一个二叉树，检查它是否是镜像对称的。
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

bool symmetric(TreeNode *left, TreeNode *right)
{
    bool res = true;
    if (left == NULL && right == NULL)
        return res;
    if (left == NULL || right == NULL)
        return false;
    
    if (left->val == right->val)
        res &= symmetric(left->left, right->right) && symmetric(left->right, right->left);
    else
        return false;
    return res;
}

bool isSymmetric(TreeNode* root)
{
    /*
        判断左子树的左节点和右子树的右节点，左子树的右节点和右子树的左节点是否一样。
        迭代判断所有。
    */
   
    return symmetric(root, root);
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->right = t5;
    t2->right = t6;
    t3->left = t7;
    

    cout << boolalpha << isSymmetric(t1);
    return 0;
}