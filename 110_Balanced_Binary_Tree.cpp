/** 给定一个二叉树，判断它是否是深度平衡的。
 *  每个节点的两个子树的深度区别不超过 1 。
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

int countDepth(TreeNode *node)
{
    if (!node)
        return 0;
    return max(countDepth(node->left), countDepth(node->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
    /*
        迭代计算当前节点中每个子树的深度，如果小于等于1则满足条件。
        判断根节点后，循环判断每个节点，都要满足条件。
    */

    if (!root)
        return true;
    int leftDepth = countDepth(root->left);
    int rightDepth = countDepth(root->right);

    return abs(leftDepth-rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);//第一个仅判断根节点，之后要判断每个节点
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
    t4->left = t6;
    t5->right = t7;

    cout << boolalpha << isBalanced(t1);
    return 0;
}