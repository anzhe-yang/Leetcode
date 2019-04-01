/** 问题描述：
 *  给定一个二叉树，返回其节点值的中序遍历。
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

vector<int> inorderTraversal(TreeNode* root)
{
    /*
        二叉树中序排列。
        押入顺序为遍历左节点、访问根节点、再遍历右节点。
        建立一个堆栈，判断当前节点是否是叶节点，如果不是，押入堆栈，并指向左节点。
        最后找到最下面的左节点，即堆栈的top节点，押入res，并pop首元素，即堆栈顶部为根节点。
        将根节点押入res，之后指向右节点，并押入堆栈，押入res。
        当temp指向NULL并且堆栈为空，则循环结束。
    */
   
    TreeNode *temp = root;
    stack<TreeNode *> t;
    vector<int> res;
    while (temp || t.empty()==0)
    {
        while (temp)
        {
            t.push(temp);
            temp = temp->left;
        }
        TreeNode *p = t.top();
        res.push_back(p->val);
        t.pop();
        temp = p->right;        
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

    vector<int> res = inorderTraversal(t1);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
