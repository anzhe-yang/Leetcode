/** 问题描述：
 *  排序一个链表。
 *  时间复杂度为 O(NlogN) ，空间复杂度为 O(1) 。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *start = new ListNode(0);
    ListNode *res = start;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            res->next = l1;
            l1 = l1->next;
        }
        else
        {
            res->next = l2;
            l2 = l2->next;
        }
        res = res->next;
    }

    res->next = l1 ? l1 : l2;
    return start->next;
}

ListNode* sortList(ListNode* head)
{
    /*
        首先通过两个变量去找链表的中心点
        变量pre表示前半个链表最后一个节点。
        所以将pre的next置为NULL，将链表分成两个链表。
        循环上述工作，直到分不开为止。
        然后进行合并操作。
        定义一个辅助链表res。
        它下一个节点指向l1和l2中值较小的那个。
        最后返回它。
    */
   
    if (!head || !head->next)
        return head;
    
    ListNode *slow = head, *fast = head;
    ListNode *pre = NULL;
    while (fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;

    ListNode *half1 = sortList(head);
    ListNode *half2 = sortList(slow);

    return merge(half1, half2);
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode *res = sortList(l1);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
