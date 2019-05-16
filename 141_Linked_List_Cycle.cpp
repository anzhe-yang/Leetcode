/** 问题描述：
 *  给定一个链表，判断它是否是环形链表。
 *  为了表示环形，使用一个整数 pos 表示链表尾部连接到链表中的索引。
 *  如果 pos 为 -1 则认为此链表无环。
 *  空间复杂度为 O(1) 。
 */

#include <iostream>

using namespace std;

 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    /*
        使用两个链表变量。
        一个每次移动一步，另一个每次移动两步。
        首先判断快的那个变量，下一个是不是NULL，下下一个是不是NULL。
        如果不是就进行移动，如果慢的值等于快的值，就说明进入循环状态了。
        因为快的肯定先进入循环，慢的进入循环时，快的可能又循环回来了。
        通过这个可以判断链表是否有环。
    */
   
    if (!head)
        return false;
    
    ListNode *slow = head;
    ListNode *quick = head;
    while (quick->next && quick->next->next)
    {
        slow = slow->next;
        quick = quick->next->next;

        if (slow->val == quick->val)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    l1->next = l2;
    l2->next = l1;
    int pos = 0;

    cout << boolalpha << hasCycle(l1);
    return 0;
}
