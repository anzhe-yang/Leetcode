/** 问题描述：
 *  合并 k 个有序链表，返回为一个链表。
 *  分析复杂度。
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *start = new ListNode(0);
    ListNode *merge = start;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            merge->next = l1;
            l1 = l1->next;
        }
        else
        {
            merge->next = l2;
            l2 = l2->next;
        }
        merge = merge->next;
    }
    merge->next = l1 ? l1 : l2;
    return start->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right)
{
    if (left == right)
        return lists[left];
    else if (left+1 == right)
        return mergeTwoLists(lists[left], lists[right]);
    ListNode *n1 = mergeKLists(lists, left, (left+right)/2);
    ListNode *n2 = mergeKLists(lists, (left+right)/2+1, right);
    return mergeTwoLists(n1, n2);
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    /*
        将lists数组从中间切开（left+right）/2。
        利用递归的方法合并两个链表，最终合并n1和n2。
        把大问题化成小问题，最终合并。
    */

    int k = lists.size();
    if (k == 0)
        return NULL;
    if (k == 1)
        return lists[0];
    return mergeKLists(lists, 0, k-1);
    
    /*
        依次合并两个链表，保存在lists[0]中。
    */

    // int k = lists.size();
    // if (k == 0)
    //     return NULL;
    // int i = 1;
    // while (i < k)
    // {
    //     for (int s = 0; s < k-i; s+=i*2)
    //         lists[s] = mergeTwoLists(lists[s], lists[s+i]);
    //     i *= 2;
    // }
    // return lists[0];
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l12 = new ListNode(4);
    l1->next = l12;
    ListNode *l13 = new ListNode(5);
    l12->next = l13;

    ListNode *l2 = new ListNode(1);
    ListNode *l22 = new ListNode(3);
    l2->next = l22;
    ListNode *l23 = new ListNode(4);
    l22->next = l23;

    ListNode *l3 = new ListNode(2);
    ListNode *l32 = new ListNode(6);
    l3->next = l32;

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3); 
    ListNode *res = mergeKLists(lists);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
