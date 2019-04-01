/** 问题描述：
 *  给定一个二叉树，从底向上返回每层的节点值。
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

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    /*
        将102题的结果进行reverse。
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
    reverse(res.begin(), res.end());
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

    vector<vector<int>> res = levelOrderBottom(t1);
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
