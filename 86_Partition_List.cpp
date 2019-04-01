/** 问题描述：
 *  给定一个链表和一个固定值，分割所有小于固定值的节点值，使这些节点位于所有大于等于固定值的节点之前。
 *  保留原始链表。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x)
{
    /*
        建立两个链表，一个保存所有小于x的节点值，一个保存所有大于等于x的节点值。
        while循环后将之后的那个链表指向NULL，让链表不会永久循环。
        之后将第一个链表的最后一个节点指向另一个链表的头节点。
        之后返回第一个链表的头节点的下一个指向。
    */

    if (!head)
        return 0;
    
    ListNode* start = new ListNode(0);
    ListNode* before = start;
    ListNode* end = new ListNode(0);
    ListNode* after = end;

    while (head)
    {
        if (head->val < x)
        {
            before->next = head;
            before = before->next;
        }
        else
        {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = end->next;
    return start->next;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = NULL;

    int x = 3;
    ListNode* res = partition(l1, x);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
