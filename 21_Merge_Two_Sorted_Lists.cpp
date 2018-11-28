/** 问题描述：
 *  合并两个已经排好序的链表，并返回一个新的链表。
 *  新的链表应当通过拼接前两个链表的结点来完成。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    /*
        定义一个顶点链表，再定义合并链表为顶点链表。
        比较当前l1和l2结点的大小，取小的放入合并链表的next，之后合并链表指向next。
        当一个链表结束后，将合并链表直接指向另一个链表，因为每个链表都是有序的。
        返回从第二个结点开始的合并链表。
    */

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

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l12 = new ListNode(2);
    l1->next = l12;
    ListNode *l13 = new ListNode(4);
    l12->next = l13;

    ListNode *l2 = new ListNode(1);
    ListNode *l22 = new ListNode(3);
    l2->next = l22;
    ListNode *l23 = new ListNode(4);
    l22->next = l23;

    ListNode *res = mergeTwoLists(l1, l2);
    while (res != NULL)
    {
        if (res->next != NULL)
            cout << res->val << "->";
        else
            cout << res->val;
        res = res->next;
    }
    return 0;
}
