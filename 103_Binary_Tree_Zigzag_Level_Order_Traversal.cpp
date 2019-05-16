/** 问题描述：
 *  给定一个二叉树，返回它的 zigzag 顺序节点值。
 *  从左到右，再从右到左。
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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    /*
        与102题相似。
        不同地方在于利用一个位置变量index。
        当是单数行，则从右往左，则index从最后的索引往前走进行赋值。
        双数行就恢复为原来的赋值方法。
    */

    vector<vector<int>> res;
    if (root == NULL)
        return res;
    
    deque<TreeNode*> cur;
    cur.push_back(root);
    bool lr = true;
    while (cur.size() > 0)
    {
        int curLevelSize = cur.size();
        vector<int> row(curLevelSize);
        for (int i = 0; i < curLevelSize; i++)
        {
            TreeNode *node = cur.front();
            cur.pop_front();
            int index = (lr) ? i : (curLevelSize-1-i);
            row[index] = node->val;
            if (node->left)
                cur.push_back(node->left);
            if (node->right)
                cur.push_back(node->right);
        }
        lr = !lr;
        res.push_back(row);
    }
    return res; 
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->right = t5;

    vector<vector<int>> res = zigzagLevelOrder(t1);
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
