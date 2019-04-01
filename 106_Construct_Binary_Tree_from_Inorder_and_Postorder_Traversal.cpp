/** 问题描述：
 *  给定一个中序和后序二叉树序列，构建这个二叉树。
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

TreeNode* buildSubTree(int* startInOrder, int* endInOrder, int* startPostOrder, int* endPostOrder)
{
    TreeNode *root = new TreeNode(*endPostOrder);

    if (startInOrder == endInOrder && startPostOrder == endPostOrder)
    {
        if (*startInOrder == *startPostOrder)
            return root;
    }

    int *rootInOrder = startInOrder;
    int rootValue = *endPostOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
    {
        rootInOrder++;
    }
    int lenOfLeft = rootInOrder - startInOrder;
    int lenOfRight = endInOrder - startInOrder - lenOfLeft;
    if (lenOfLeft > 0)
    {
        root->left = buildSubTree(startInOrder, rootInOrder-1, startPostOrder, startPostOrder+lenOfLeft-1);
    }
    if (lenOfRight > 0)
    {
        root->right = buildSubTree(rootInOrder+1, endInOrder, startPostOrder+lenOfLeft, endPostOrder-1);
    }
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    /*
        迭代法。
        先找出当前层的根节点，然后找出左子树的长度和右子树的长度。
        根节点即为postorder的最后一个元素。
        循环找出所有节点。
    */

    if (inorder.empty() || postorder.empty())
        return NULL;
    
    return buildSubTree(&inorder.front(), &inorder.back(), &postorder.front(), &postorder.back());
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
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};
    TreeNode *res = buildTree(inorder, postorder);
    traversalTrees(res);
    return 0;
}
