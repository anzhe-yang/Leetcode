/** 问题描述：
 *  给定一个前序和中序二叉树序列，构建这个二叉树。
 *  二叉树中不存在重复的数值。
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
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

TreeNode* buildSubTree(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder)
{
    TreeNode *root = new TreeNode(*startPreOrder);

    if (startPreOrder == endPreOrder && startInOrder == endInOrder)
    {
        if (*startPreOrder == *startInOrder)
            return root;
    }

    int *rootInOrder = startInOrder;
    int rootValue = *startPreOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
    {
        rootInOrder++;
    }
    int lenOfLeft = rootInOrder - startInOrder;
    int lenOfRight = endInOrder - startInOrder - lenOfLeft;
    if (lenOfLeft > 0)
    {
        root->left = buildSubTree(startPreOrder+1, startPreOrder+lenOfLeft, startInOrder, rootInOrder-1);
    }
    if (lenOfRight > 0)
    // if (lenOfLeft < endPreOrder - startPreOrder)
    {
        root->right = buildSubTree(startPreOrder+lenOfLeft+1, endPreOrder, rootInOrder+1, endInOrder);
    }
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    /*
        迭代法。
        先找出当前层的根节点，然后找出左子树的长度和右子树的长度。
        根节点即为preorder第一个元素。
        循环找出所有节点。
    */

    if (preorder.empty() || inorder.empty())
        return NULL;
    
    return buildSubTree(&preorder.front(), &preorder.back(), &inorder.front(), &inorder.back());
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
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode *res = buildTree(preorder, inorder);
    traversalTrees(res);
    return 0;
}
