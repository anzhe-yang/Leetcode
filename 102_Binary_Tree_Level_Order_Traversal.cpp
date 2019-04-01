/** 问题描述：
 *  给定一个二叉树，按照它自己的顺序，从左到右的节点值，返回每一级的的节点值。
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

vector<vector<int>> levelOrder(TreeNode* root)
{
    /*
        建立两个队列变量cur，next。
        cur代表当前层所有节点。
        next将当前层所有节点保存起来，用来寻找下一层所有节点，也就是把当前层每一个节点的left和right节点都找出来。
        while循环中第一个while将所有cur节点值保存在res的某个level中，同时next将当前层所有节点保存起来，用于下一层节点的寻找。
        第二个while将当前节点的所有下一层节点找出来，并保存在cur中，用于下一循环中。
    */

    vector<vector<int>> res;
    if (root == NULL)
        return res;
    
    int level = 0;
    deque<TreeNode*> cur;
    cur.push_back(root);
    deque<TreeNode*> next;
    while (cur.size() > 0)
    {
        res.push_back(vector<int>());//二维vector向量初始化需要这一步
        while (!cur.empty())
        {
            TreeNode *node = cur.front();
            next.push_back(node);
            cur.pop_front();
            res[level].push_back(node->val);
        }
        level++;

        while (!next.empty())
        {
            TreeNode *node = next.front();
            next.pop_front();
            if (node->left)
                cur.push_back(node->left);
            if (node->right)
                cur.push_back(node->right);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);
    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;

    vector<vector<int>> res = levelOrder(t1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
