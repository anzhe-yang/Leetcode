/** 问题描述：
 *  给定一个链表，每两个相邻链表节点做一次交换，并返回链表的头节点。
 *  假设你无法修改链表中节点的值，只能修改链表的连接。
 *  算法只能使用额外的线性空间。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
    /*
        用指向指针的指针pp指向head的地址。
        循环中前三行做的事情是使head->a->b->(b->next)变为head->b->a->(b->next)。
        最后使pp指向a->next也就是之前的b->next的地址。
    */

    // ListNode **pp = &head;
    // ListNode *a, *b;
    // while ((a = *pp) && (b = a->next)) 
    // {
    //     a->next = b->next;
    //     b->next = a;
    //     *pp = b;
    //     pp = &(a->next);
    // }
    // return head;

    /*
        p是当前的头节点，q是两个节点之后的头节点，也就是下次做变换的头节点。
        之后两行做的是交换工作，最后p->next是下次做变换的头节点，也就是q，开始做交换工作。
        但使用递归之后可能占有空间不再是线性的了。
    */

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    ListNode *p = head;
    ListNode *q = head->next->next;
    head = head->next;
    head->next = p;
    p->next = swapPairs(q);
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l12 = new ListNode(2);
    l1->next = l12;
    ListNode *l13 = new ListNode(3);
    l12->next = l13;
    ListNode *l14 = new ListNode(4);
    l13->next = l14;

    ListNode *res = swapPairs(l1);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
