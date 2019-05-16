/** 问题描述：
 *  给定一个二叉树，返回节点的前序遍历。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *node, vector<int> &res)
{
    if (!node)
    {
        return ;
    }

    res.push_back(node->val);
    if (node->left)
    {
        preOrder(node->left, res);
    }
    if (node->right)
    {
        preOrder(node->right, res);
    }
}

vector<int> preorderTraversal(TreeNode* root)
{
    /*
        回溯法。
    */

    // vector<int> res;
    // preOrder(root, res);
    // return res;

    /*
        使用栈保存要遍历的节点。
        重点是先保存右节点，再保存左节点。
        因为弹出是先入后出。
    */
   
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode*> treeStack;
    treeStack.push(root);
    while (!treeStack.empty())
    {
        TreeNode *temp = treeStack.top();
        res.push_back(temp->val);
        treeStack.pop();
        if (temp->right)
        {
            treeStack.push(temp->right);
        }
        if (temp->left)
        {
            treeStack.push(temp->left);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    t1->left = t2;
    t1->right = t3;

    vector<int> res = preorderTraversal(t1);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}
