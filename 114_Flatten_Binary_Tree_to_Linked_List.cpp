/** 问题描述：
 *  给定一个二叉树，将其平铺成链表。
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

TreeNode *pre = NULL;

void flatten(TreeNode* root)
{
    /*
        将左子树的所有节点转移到root的右节点上。
        先找到最右最大的节点，然后依次向上回溯，找到次大的节点即pre，放在root的右节点。
    */

    if (root == NULL)
        return ;
    flatten(root->right);
    flatten(root->left);
    root->right = pre;
    root->left = NULL;
    pre = root;
}

void traversalTrees(TreeNode* tree)
{
    deque<TreeNode*> d;
    d.push_back(tree);
    while (d.size() != 0)
    {
        TreeNode *temp = d.front();
        d.pop_front();
        if (temp->val == -1)
        {
            cout << "null ";
        }
        else
        {
            cout << temp->val << " ";
        }     

        if (temp->left)
        {
            d.push_back(temp->left);
            if (!temp->right)
                d.push_back(new TreeNode(-1));
        }

        if (temp->right)
        {
            if (!temp->left)
                d.push_back(new TreeNode(-1));
            d.push_back(temp->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(6);
    t1->left = t2;
    t1->right = t5;
    t2->left = t3;
    t2->right = t4;
    t5->right = t6;

    flatten(t1);
    traversalTrees(t1);
    return 0;
}
