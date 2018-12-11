/** 问题描述：
 *  给定一个链表，把链表中的数值向右移动 k 个位置。
 *  假设 k 是非负整数。
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

ListNode* rotateRight(ListNode* head, int k)
{
    /*
        首先找到移动后链表的第一个元素应该是什么。
        应该是原链表的第len-k个元素。
        之后就是建立新链表，指向第len-k个元素，之后从头开始指向。
    */
   
    if (!head)
        return head;
    
    int len = 1;
    ListNode *count, *res;
    count = res = head;
    while (count->next != NULL)
    {
        count = count->next;
        len++;
    }
    count->next = head;//使得count无线循环原链表：1 2 3 4 5 1 2 3 4 5 
    if (k %= len)//判断k是否是len的整数倍数，如果是，则不用移动，返回原链表
    {
        for (int i = 0; i < len-k; i++)//len-k代表了移动后的链表的首元素在原链表中的位置。
            count = count->next;
    }
    res = count->next;//指向新链表的首元素
    count->next = NULL;//停止，不让它无限循环下去，不写这个就无限循环链表
    return res;
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

    int k = 2;
    ListNode *res = rotateRight(l1, k);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
