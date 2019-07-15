/** 问题描述：
 *  在二叉搜索树上实现一个迭代器，初始化在根节点上。
 *  函数 next() 返回二叉树中下一个最小的元素，算法复杂度为 O(1) 。
 *  函数 hasNext() 返回是否有下一个元素，算法复杂度为 O(H) ， H 为二叉树的高度。
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
    /*
        先前序遍历整个二叉树，并把元素按大小排序，保存在数组里。
        初始化时，遍历整个二叉树，并初始化位置坐标index。
        每次返回当前位置的元素，并将坐标+1。
        如果坐标大于数组大小，则返回false。
    */
public:
    int index;

    BSTIterator(TreeNode* root)
    {
        createArray(root, nodeVal);
        index = 0;
    }

    int next()
    {
        return nodeVal[index++];
    }

    bool hasNext()
    {
        if (index < nodeVal.size())
            return true;
        else
            return false;
    }

private:
    vector<int> nodeVal;
    void createArray(TreeNode *root, vector<int> &nodeVal)
    {
        if (!root)
        {
            return ;
        }

        if (root->left)
        {
            createArray(root->left, nodeVal);
        }
        nodeVal.push_back(root->val);
        createArray(root->right, nodeVal);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *l1 = new TreeNode(7);
    TreeNode *l2 = new TreeNode(3);
    TreeNode *l3 = new TreeNode(15);
    TreeNode *l4 = new TreeNode(9);
    TreeNode *l5 = new TreeNode(20);
    l1->left = l2;
    l1->right = l3;
    l3->left = l4;
    l3->right = l5;

    BSTIterator *obj = new BSTIterator(l1);
    int p1 = obj->next();
    bool p2 = obj->hasNext();
    int p3 = obj->next();
    
    cout << p1 << endl;
    cout << boolalpha << p2 << endl;
    cout << p3 << endl;
    return 0;
}
