/** 问题描述：
 *  给定一个二叉树和一个总和，找到此树中所有从根节点到叶节点的路径之和等于特定值。
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

void findPath(TreeNode *node, int sum, vector<vector<int>> &res, vector<int> &cur_node)
{
    if (node == NULL)
    {
        return ;
    }

    cur_node.push_back(node->val);
    if (node->left == NULL && node->right == NULL && sum-node->val == 0)
    {
        res.push_back(cur_node);
    }
    
    findPath(node->left, sum-node->val, res, cur_node);
    findPath(node->right, sum-node->val, res, cur_node);
    cur_node.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    /*
        回溯法。
        关键点在于，先将当前节点入栈，再判断当前节点是否是叶节点，同时sum之后是否就为0，如果满足，将此加入res。
        循环调用左节点和右节点。
        另一个关键点在于，如果不满足终止条件，向上回掉前，要先pop出最上面的元素，直到满足条件位置。
        否则如果每次都清空，则无根节点元素。这样就一直回掉到满足条件的那个位置，之后的元素就不pop了，即根节点永远不pop，除非全部循环完毕。
    */
    
    vector<vector<int>> res;
    vector<int> cur_node;
    findPath(root, sum, res, cur_node);
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(8);
    TreeNode *t4 = new TreeNode(11);
    TreeNode *t5 = new TreeNode(13);
    TreeNode *t6 = new TreeNode(4);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(2);
    TreeNode *t9 = new TreeNode(5);
    TreeNode *t10 = new TreeNode(1);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->left = t5;
    t3->right = t6;
    t4->left = t7;
    t4->right = t8;
    t6->left = t9;
    t6->right = t10;

    int sum = 22;
    vector<vector<int>> res = pathSum(t1, sum);
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
