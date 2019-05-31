/** 问题描述：
 *  写一个程序来查找两个单独链表开始相交的节点。
 *  如果两个链表没有相交，返回 NULL 。
 *  假设链表没有环。
 *  算法的时间复杂度为 O(N) ，空间复杂度为 O(1) 。
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    /*
        定义两个链表指针，每个都以此往前走。
        当l1到头了，将l1指向headB。
        当l2到头了，将l2指向headA。
        这样循环之后，总会有l1和l2相遇的一天，这时返回某个指针变量。
        因为一旦重新分配起点的时候，例如当l1走到头了，变成headB，而l2还没走到头，这时他俩到相遇点的距离是一样的。
        所以算法收敛，它们总能相遇。
        时间复杂度为O(M+N)。
    */

    ListNode *l1 = headA;
    ListNode *l2 = headB;

    if (!l1 || !l2)
        return NULL;
    
    while (l1 && l2 && l1!=l2)
    {
        l1 = l1->next;
        l2 = l2->next;

        if (l1 == l2)
            return l1;
        
        if (!l1)
            l1 = headB;
        if (!l2)
            l2 = headA;
    }
    return l1;
}

int main(int argc, char const *argv[])
{
    ListNode *la1 = new ListNode(4);
    ListNode *la2 = new ListNode(1);

    ListNode *lb1 = new ListNode(5);
    ListNode *lb2 = new ListNode(0);
    ListNode *lb3 = new ListNode(1);

    ListNode *lc1 = new ListNode(8);
    ListNode *lc2 = new ListNode(4);
    ListNode *lc3 = new ListNode(5);

    la1->next = la2;
    la2->next = lc1;

    lb1->next = lb2;
    lb2->next = lb3;
    lb3->next = lc1;

    lc1->next = lc2;
    lc2->next = lc3;

    cout << getIntersectionNode(la1, lb1)->val;
    return 0;
}
