/** 问题描述：
 *  使用插入排序算法排序一个链表。
 *  每次迭代时插入一个输入元素，并生成排序好的输出链表。
 *  每次迭代时，从输入数据中删除一个元素，在链表中找到其位置并插入。
 *  直到没有输入元素时停止。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head)
{
    /*
        定义两个节点变量，分别为头节点pre和下一节点next。
        每次先将下一个节点保存到next，在判断以排序的链表是否最大值小于当前节点head->val。
        如果大于，则说明当前节点要插入进去，即替换之。
        替换完后要将pre指回头节点，然后head指向下一节点next，即head=head->next。
    */

    // if (!head)
    //     return head;
    
    // ListNode *start = new ListNode(0);
    // ListNode *pre = start;
    // ListNode *next = NULL;
    // while (head)
    // {
    //     next = head->next;
    //     while (pre->next && pre->next->val < head->val)
    //     {
    //         pre = pre->next;
    //     }
    //     head->next = pre->next;
    //     pre->next = head;
    //     pre = start;
    //     head = next;
    // }
    // return start->next;

    /*
        这种方法，当以排好序的链表最大值都小于当前节点时，不做替换操作。
        当大于当前节点值时，找到小于当前节点值的最后一个位置，然后替换。
        之后将pre指回头节点。
        省略了很多次替换操作。
    */
   
    ListNode *start = new ListNode(INT_MIN);
    start->next = head;
    ListNode *pre = start;
    ListNode *cur = head;
    while (cur->next)
    {
        if (cur->val > cur->next->val)
        {
            while (pre->next->val < cur->next->val)
            {
                pre = pre->next;
            }
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
            
            pre = start;
        }
        else
        {
            cur = cur->next;
        }
    }
    return start->next;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode *res = insertionSortList(l1);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
