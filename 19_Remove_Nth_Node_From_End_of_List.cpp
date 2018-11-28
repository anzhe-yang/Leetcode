/** 问题描述：
 *  给定一个链表，从链表的末尾开始删除第 n 个结点，并返回链表的头结点。
 *  假设给定的 n 是有效的。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    /*  
        用k来计算整个链表的长度，如果n==k，则删除的是头结点，所以将头结点指向下一个并返回。
        之后prev代表前一结点，temp代表当前结点，利用while使得tmp指向第n个之后的结点，若循环结束时满足两个条件，则temp就是要删除的那个结点。
    */

    int k = 0;
    ListNode *len = head;
    while (len != NULL)
    {
        k++;
        len = len->next;
    }
    if (k == n)
    {
        head = head->next;
        return head;
    }

    ListNode *temp = head;

    while (temp->next != NULL)
    {
        ListNode *prev = temp;
        temp = temp->next;
        ListNode *tmp = temp;
        int i = 0;
        while (tmp != NULL && i < n)
        {
            tmp = tmp->next;
            i++;
        }
        if (i == n && tmp == NULL)
        {
            prev->next = temp->next;
            break;
        }
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next =  node2;
    ListNode *node3 = new ListNode(3);
    node2->next = node3;
    ListNode *node4 = new ListNode(4);
    node3->next = node4;
    ListNode *node5 = new ListNode(5);
    node4->next = node5;
    node5->next = NULL;

    int n = 5;
    ListNode *list = removeNthFromEnd(node1, n);

    while(list != NULL)
    {
        cout << list->val << " ";
        list = list->next;
    }
    return 0;
}
