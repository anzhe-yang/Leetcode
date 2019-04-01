/** 问题描述：
 *  将一个链表中从位置 m 到位置 n 进行反转。
 *  时间复杂度为 N 。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    /*
        循环反转n-m次。
        第一次反转前两个节点。
        第一次反转后的后节点不再管他，放在最后，再反转前两个节点。
        以此类推。
    */

    if (!head)
        return 0;    
    ListNode *start = new ListNode(0);
    ListNode *pre = start;
    pre->next = head;
    for (int i = 1; i < m; i++)
    {
        pre = pre->next;
    }
    ListNode *cur = pre->next;//cur指向反转的第一个节点
    for (int i = 0; i < n-m; i++)//循环n-m次
    {
        ListNode *mov = cur->next;//mov指向当前反转后的第一个节点，也就是pre后的节点
        cur->next = mov->next;//cur->next指向下一次循环所要反转的节点
        mov->next = pre->next;//将mov与cur进行反转
        pre->next = mov;//反转完成，将pre->next指向mov
    }// 1 2 3 4 5 -> 1 3 2 4 5 -> 1 4 3 2 5
    ListNode *temp = start->next;
    delete start;//防止内存泄漏操作
    return temp;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    int m = 2, n = 4;
    ListNode *res = reverseBetween(l1, m, n);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
