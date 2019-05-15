/** 问题描述：
 *  给定一个链表，返回此链表环形开始的节点，如果不是环形链表，则返回 NULL 。
 *  为了表示环形，使用一个整数 pos 表示链表尾部连接到链表中的索引。
 *  如果 pos 为 -1 则认为此链表无环。
 *  不使用额外的空间。
 */

#include <iostream>
#include <unordered_set>

using namespace std;

 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    /*
        这个方法使用了额外的空间，保存已遍历的节点。
        如果slow节点遍历到了已保存过的节点的话，返回slow。
    */
   
    // if (!head)
    //     return NULL;
    
    // ListNode *slow = head;
    // ListNode *quick = head->next;
    // unordered_set<int> set;
    // set.insert(quick->val);
    // while (slow->next && slow->next->next)
    // {
    //     slow = slow->next;
    //     quick = slow->next;
    //     set.insert(quick->val);
    //     if (set.find(slow->val) != set.end())
    //     {
    //         return slow;
    //     }
    // }
    // return NULL;

    /*
        首先通过上一题来判断此链表是否有环，一个节点走一步，一个节点走两步。
        循环的长度为r。
        当这两个节点相遇时，说明有环，记录相遇节点，从head到此相遇节点的距离为k。
        方法要找的结果是从head到循环起始节点的距离，记为s。
        循环起始节点到相遇节点的距离为m，所以s=k-m。
        通过上一题得到：2k-k=nr   k=nr。
        即s=nr-m=(n-1)r+(r-m)，当取n=1时。
        即从head出发，每次走一步，然后另一个从相遇点出发，每次走一步。
        当这两个节点相遇时，即为循环起始节点。
        因为循环的长度和循环起始节点到相遇节点的距离的差值，再*n即为s，不考虑n，就为上述所说的步骤，一直走，当相遇时记为循环起始节点。
    */

    if (!head)
        return NULL;
    
    bool isCycle = false;
    ListNode *slow = head;
    ListNode *quick = head;
    while (quick->next && quick->next->next)
    {
        slow = slow->next;
        quick = quick->next->next;

        if (slow == quick)
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
    {
        ListNode *cycleNode = head;
        while (cycleNode != quick)
        {
            cycleNode = cycleNode->next;
            quick = quick->next;
        }
        return cycleNode;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = new ListNode(3);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(-4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l2;
    int pos = 0;

    // assert(detectCycle(l1)->val == l2->val);
    cout << detectCycle(l1)->val;
    return 0;
}
