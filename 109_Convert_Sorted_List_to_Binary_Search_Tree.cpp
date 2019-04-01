/** 问题描述：
 *  给定一个升序排列的链表，转化成一个高度平衡的 BST 。
 *  其中每个节点的两个子树深度相差不能超过 1 。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL) {} 
};

TreeNode* sortedListSubTree(ListNode *start, ListNode *end)
{
    if (start == end)
        return NULL;
    
    ListNode *midNode = start;
    ListNode *temp = start;
    while (temp!=end && temp->next!=end)//重点！！！找root节点。
    {
        midNode = midNode->next;//一个每次移动一个节点
        temp = temp->next->next;//一个每次移动两个节点
    }//当temp到达终点，则mid刚好到达中间点
    TreeNode *root = new TreeNode(midNode->val);
    root->left = sortedListSubTree(start, midNode);
    root->right = sortedListSubTree(midNode->next, end);
    return root;
}

TreeNode* sortedListToBST(ListNode* head)
{
    /*
        回溯法。
        找中间点。
    */
   
    return sortedListSubTree(head, NULL);
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
    ListNode *l1 = new ListNode(-10);
    ListNode *l2 = new ListNode(-3);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(9);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    TreeNode *res = sortedListToBST(l1);
    traversalTrees(res);
    return 0;
}