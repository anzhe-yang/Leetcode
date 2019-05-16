/** 问题描述：
 *  给定一个非空二叉树，找到最大路径和。
 *  在这个问题中，路径被定义为沿着父节点从某个起始点开始到任何节点的序列。
 *  该路径必须至少包含一个节点，并且不需要通过根节点。
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

int maxVal;

int maxSum(TreeNode *node)
{
    if (!node)
        return 0;
    
    int left = max(0, maxSum(node->left));
    int right = max(0, maxSum(node->right));
    maxVal = max(maxVal, node->val+left+right);
    return max(left, right)+node->val;
}

int maxPathSum(TreeNode* root)
{
    /*
        找到一个节点和其两个子节点，使其和最大。
        左右节点找值最大的。
        之后加上其父节点值，找值最大的。
        最后返回。
    */
   
    maxVal = INT_MIN;
    maxSum(root);
    return maxVal;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(-10);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;

    cout << maxPathSum(t1);
    return 0;
}
