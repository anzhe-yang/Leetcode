/** 问题描述：
 *  给定两个非空链表，分别表示两个非负整数。数字以相反的顺序存储，每个节点仅包含单独一个数字。将两个数字加起来，并将其作为链表用逆顺序返回。
 *  假设这两个数字中零不在首位，除了零本身。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    /*
        carry为相加之和，用除余运算分别进行链表操作。
    */

    int carry = 0;
    ListNode *res = NULL, *temp = NULL;
    while (l1 or l2 or carry)
    {
        if (l1)
        {
            carry = carry + l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            carry = carry + l2->val;
            l2 = l2->next;
        }

        if (temp)
        {
            temp->next = new ListNode(carry%10);
            temp = temp->next;
        }
        else
            temp = res = new ListNode(carry%10);

        carry = carry / 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(2);//2 -> 4 -> 3
    ListNode *s1 = new ListNode(4);
    s1->next = l1->next;
    l1->next = s1;
    ListNode *s2 = new ListNode(3);
    s2->next = s1->next;
    s1->next = s2;
    s2->next = NULL;

    ListNode *l2 = new ListNode(5);//5 -> 6 -> 4
    ListNode *m1 = new ListNode(6);
    m1->next = l2->next;
    l2->next = m1;
    ListNode *m2 = new ListNode(4);
    m2->next = m1->next;
    m1->next = m2;
    m2->next = NULL;

    // ListNode *l1 = new ListNode(5);
    // l1->next = NULL;
    // ListNode *l2 = new ListNode(5);
    // l2->next = NULL;

    ListNode *result = addTwoNumbers(l1, l2);
    while (result != NULL)
    {
        cout << result->val;
        result = result->next;
        if (result != NULL)
            cout << " -> ";
    }
    return 0;
}