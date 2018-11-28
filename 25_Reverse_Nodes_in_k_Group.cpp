/** 问题描述：
 *  给定一个链表，每次反转链表中 k 个节点，并返回反转后的链表。
 *  k 是正整数，小于或等于链表的长度。
 *  若链表的节点数不是 k 的倍数，那么最后的剩余节点应保持不变。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
    /*
        先计算链表的长度，然后按照k个节点一轮次进行操作。
        012345->021345->032145。
        用pre->next指向nex，而nex->next指向cur->next。
    */
   
    if (head == NULL || k == 1)
        return head;
    ListNode *start = new ListNode(0);
    start->next = head;
    ListNode *pre, *cur, *nex;
    cur = start;
    pre = start;
    int num = 0;
    while (cur = cur->next)//计算链表的长度
        num++;
    while (num >= k)//k个节点迭代一次
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num -= k;
    }
    return start->next;
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
    ListNode *l15 = new ListNode(5);
    l14->next = l15;

    int k = 3;
    ListNode *res = reverseKGroup(l1, k);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
