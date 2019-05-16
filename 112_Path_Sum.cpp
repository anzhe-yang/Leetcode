/** 问题描述：
 *  给定一个二叉树和一个总和，判断此树是否有一条从根节点到叶节点的路径，使其总和等于其值。
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

bool hasPathSum(TreeNode* root, int sum)
{
    /*
        如果当前val等于sum，并且是叶节点，则返回true。
        迭代判断所有路径，用或运算。
        迭代到当前节点为NULL时，当前路径为false。
    */
   
    if (root == NULL)
        return false;
    if (root->val == sum && !root->left && !root->right)
        return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

int main(int argc, char const *argv[])
{
    // TreeNode *t1 = new TreeNode(5);
    // TreeNode *t2 = new TreeNode(4);
    // TreeNode *t3 = new TreeNode(8);
    // TreeNode *t4 = new TreeNode(11);
    // TreeNode *t5 = new TreeNode(13);
    // TreeNode *t6 = new TreeNode(4);
    // TreeNode *t7 = new TreeNode(7);
    // TreeNode *t8 = new TreeNode(2);
    // TreeNode *t9 = new TreeNode(1);
    // t1->left = t2;
    // t1->right = t3;
    // t2->left = t4;
    // t3->left = t5;
    // t3->right = t6;
    // t4->left = t7;
    // t4->right = t8;
    // t6->right = t9;
    TreeNode *t1 = new TreeNode(1);

    int sum = 0;
    cout << boolalpha << hasPathSum(t1, sum);
    return 0;
}
