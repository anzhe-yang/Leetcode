/** 问题描述：
 *  给定一个二叉树，判断它是否为符合规则的二叉搜索树（BST）。
 *  BST 的规则如下：
 *  左节点只包含比根节点小的数值。
 *  右节点只包含比根节点大的数值。
 *  每个左子树和右子树必须也是二叉搜索树。
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

bool isValidBST(TreeNode* root, TreeNode* lnode, TreeNode* rnode)
{
    if (!root)
        return true;
    if ((lnode && root->val <= lnode->val) || (rnode && root->val >= rnode->val))
        return false;
    return isValidBST(root->left, lnode, root) && isValidBST(root->right, root, rnode);
}

bool isValidBST(TreeNode* root)
{
    // if (root->val > root->left->val && root->val < root->right->val)
    // {
    //     isValidBST(root->left);
    //     isValidBST(root->right);
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    /*
        当前root节点必须大于左节点值，必须小于右节点值。
        否则false。
        之后将root指向左节点，则要小于原root。
        root指向右节点，则要大于原root。
    */
    return isValidBST(root, NULL, NULL);
}

int main(int argc, char const *argv[])
{
    // TreeNode *t1 = new TreeNode(4);
    // TreeNode *t2 = new TreeNode(1);
    // TreeNode *t3 = new TreeNode(5);
    // TreeNode *t4 = new TreeNode(3);
    // TreeNode *t5 = new TreeNode(6);
    // t1->left = t2;
    // t1->right = t3;
    // t3->left = t4;
    // t3->right = t5;
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(3);
    t1->left = t2;
    t1->right = t3;

    cout << boolalpha << isValidBST(t1);
    return 0;
}
