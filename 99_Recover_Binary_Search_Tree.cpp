/** 问题描述：
 *  一个 BST 树上的两个元素被错误的交换了。
 *  将这个树进行复原，在不改变它结构的情况下。
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

void check(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second)
{
    if (root == NULL)
        return;
    
    check(root->left, pre, first, second);

    if (first == NULL && pre->val > root->val)
        first = pre;
    
    if (first != NULL && pre->val > root->val)
        second = root;
    
    pre = root;

    check(root->right, pre, first, second);
}

void recoverTree(TreeNode* root)
{
    /*
        将二叉树进行中序排列，则排列后的数组应是从小到大按顺序的。
        当前一个树比后一个树大时，说明此数排列有问题，找出两个这样的树。
        最后将两个节点的值进行交换。
        如果在函数中会改变结构体TreeNode的指向，则需要将此变量的地址传到函数中，所以在定义时要加&。
    */
    TreeNode *pre = new TreeNode(INT_MIN);
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    check(root, pre, first, second);
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
    delete pre;
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
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(2);
    t1->left = t2;
    t2->right = t3;

    recoverTree(t1);
    traversalTrees(t1);
    return 0;
}
