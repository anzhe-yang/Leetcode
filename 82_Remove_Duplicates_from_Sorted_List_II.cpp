/** 问题描述：
 *  给定一个有序的链表，删除所有重复的数字，只留下不重复的元素。
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
        定义当前节点值为val，将temp指向下一个节点。
        如果当前temp的节点值不等于val，则说明此节点符合规则，将head的下一节点指向temp，并继续利用temp做首节点，循环迭代。
        如果等于，利用while循环找到下一个不一样的节点值，记录此节点，并作为temp，利用temp做首节点，循环迭代。
        迭代完成后，返回真正首节点head。
        每次都判断当前临时首节点temp，也就是head，的下一个节点是否为NULL，是就说明循环结束，返回真正首节点head。
        第一个if判断给定的链表第一个节点是否是NULL。
    */
   
    if (head == NULL)
        return 0;
    if (head->next == NULL)
        return head;

    int val = head->val;
    ListNode *temp = head->next;
    if (temp->val != val)
    {
        head->next = deleteDuplicates(temp);
        return head;
    }
    else
    {
        while (temp && temp->val==val)
        {
            temp = temp->next;
        }
        return deleteDuplicates(temp);
    }
}

int main(int argc, char const *argv[])
{
    // ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(1);
    // ListNode *l3 = new ListNode(1);
    // ListNode *l4 = new ListNode(2);
    // ListNode *l5 = new ListNode(3);
    // l1->next = l2;
    // l2->next = l3;
    // l3->next = l4;
    // l4->next = l5;
    // l5->next = NULL;

    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(3);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(5);
    ListNode *l7 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = NULL;
    
    ListNode *res = deleteDuplicates(l1);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
