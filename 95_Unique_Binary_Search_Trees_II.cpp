/** 问题描述：
 *  给定一个整数 n ，生成所有结构化的不重复的 BST （二叉搜索树）保存数值 1...n。
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

vector<TreeNode*> genTrees(int start, int end)
{
    vector<TreeNode*> res;
    if (start > end)
    {
        res.push_back(NULL);
        return res;
    }

    vector<TreeNode*> left, right;
    for (int i = start; i <= end; i++)
    {
        left = genTrees(start, i-1);
        right = genTrees(i+1, end);

        for (TreeNode *leftNode : left)
        {
            for (TreeNode *rightNode : right)
            {
                TreeNode *root = new TreeNode(i);
                root->left = leftNode;
                root->right = rightNode;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n)
{
    /*
        当第i个元素是根节点时，第1到i-1个元素在左节点，第i+1到n个元素在右节点。
        利用递归的方法循环得到所有左节点和右节点，最终将i->left指向左节点，i->right指向右节点。
        left是1到i-1个元素中以i/2为根结点的二叉树，right同理。
        利用foreach遍历left和right二叉树，将根节点和子节点、叶节点连接起来。
        完成一种结果，押入res。
    */

    if (n == 0)
    {
        vector<TreeNode*> res;
        return res;
    }
    return genTrees(1, n);
}

void traversalTrees(TreeNode* tree)
{
    /*
        广度优先遍历二叉树。
        先第一层，后第二层，以此类推。
    */

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
    int n = 3;
    vector<TreeNode*> res = generateTrees(n);
    for (int i = 0; i < res.size(); i++)
    {
        traversalTrees(res[i]);
        cout << endl;
    }
    return 0;
}
