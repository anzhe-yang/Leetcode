/** 问题描述：
 *  给定一个二叉树，返回节点的后序遍历。
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postOrder(TreeNode *node, vector<int> &res)
{
    if (!node)
    {
        return ;
    }

    postOrder(node->left, res);
    postOrder(node->right, res);
    res.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    /*
        回溯法。
    */
   
    // vector<int> res;
    // if (!root)
    //     return res;
    // postOrder(root, res);
    // return res;

    /*
        调用栈，先找到最下面的左节点，并保存途中每个节点，之后弹出栈顶，如果是叶节点，则压入res。
        否则查看是否有右节点，并找到右节点最下面的左节点。
        关键之处在于pre节点变量，它保存了上一次操作过的节点，遍历父节点时，如果右节点是上一次操作过的节点pre，就不进行操作，并将父节点压入res。
        如果不做这一步骤，造成内存溢出，因为算法一直在遍历这个操作过的节点。
    */
   
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode *node = root;
    TreeNode *pre = NULL;
    while (!s.empty() || node)
    {
        if (node)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            TreeNode *father = s.top();
            if (father->right && father->right != pre)
            {
                node = father->right;
            }
            else
            {
                res.push_back(father->val);
                pre = father;
                s.pop();
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    t1->right = t2;
    t2->left = t3;

    vector<int> res = postorderTraversal(t1);
    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}
