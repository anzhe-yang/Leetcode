/** 问题描述：
 *  给定一个有序的链表，删除所有重复的元素，使每个元素只出现一次。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    /*
        定义一个当前节点tmp，如果当前节点和下个节点相等，则将下个节点往下走。
    */
   
    if (!head)
        return 0;

    ListNode *tmp = head;
    while (tmp)
    {
        while (tmp->next && tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;//当tmp->next->next为NULL时，tmp->next是NULL。
        }
        tmp = tmp->next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(3);
    ListNode *l5 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    ListNode *res = deleteDuplicates(l1);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
