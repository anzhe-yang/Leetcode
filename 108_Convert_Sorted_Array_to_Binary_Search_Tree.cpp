/** 问题描述：
 *  给定一个升序排列的数组，转化成一个高度平衡的 BST 。
 *  其中每个节点的两个子树深度相差不能超过 1 。
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

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    /*
        将nums进行二分操作，当只有一个元素时，建立节点，并返回。
        每次查找中值作为根节点，然后以根节点为中心将nums分开，左边为左子树范围，右边为右子树范围。
    */

    if (nums.size() < 1)
        return NULL;
    if (nums.size() == 1)
        return new TreeNode(nums[0]);

    int len = nums.size();
    int rootPos = len / 2;
    TreeNode *root = new TreeNode(nums[rootPos]);
    vector<int> leftSubTree(nums.begin(), nums.begin()+rootPos);
    vector<int> rightSubTree(nums.begin()+rootPos+1, nums.end());

    root->left = sortedArrayToBST(leftSubTree);
    root->right = sortedArrayToBST(rightSubTree);
    return root;
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
    vector<int> nums{-10, -3, 0, 5, 9};

    TreeNode *res = sortedArrayToBST(nums);
    traversalTrees(res);
    return 0;
}