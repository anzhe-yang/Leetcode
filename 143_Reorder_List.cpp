/** 问题描述：
 *  给定一个单链表 l0 - l1 - ... - ln-1 - ln
 *  转化为 l0 - ln - l1 - ln-1 - l2 - ln-2 - ...
 *  你不能改变节点的值，只能改变节点本身。
 */

#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head)
{
    /*
        首先找链表的长度，并将长度/2即为要翻转的长度，同时将每个节点保存在队列里。
        之后开始遍历每个节点，每个节点之后都插入一个队列的头部节点，即链表最后的节点。
        结束条件是len为0。
    */
   
    deque<ListNode*> node;
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        node.push_front(temp);
        len++;
        temp = temp->next;
    }

    len /= 2;
    while (head && len > 0)
    {
        ListNode *next = head->next;
        ListNode *back = node.front();
        node.pop_front();
        len--;
        head->next = back;
        back->next = next;
        if (len == 0)
            next->next = NULL;
        head = next;
    }
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

    reorderList(l1);
    while (l1)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    return 0;
}

