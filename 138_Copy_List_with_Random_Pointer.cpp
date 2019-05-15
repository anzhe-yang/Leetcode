/** 问题描述：
 *  给定一个链表，在每个节点的性质中附加一个随机指针，该指针可以指向链表中的任何节点或者 null 。
 *  返回这个链表的深度复制。
 */

#include <iostream>

using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) 
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* copyRandomList(Node* head)
{
    /*
        先将每个节点复制一次，保存在每个节点之后。
        之后将每个节点的random->next赋值给next->random，并指向下下一个节点。
        之后将复制的节点分离，返回结果
        O(1)空间复杂度，O(N)时间复杂度。
    */
   
    if (!head)
        return NULL;

    Node *cur = head;
    while (cur)
    {
        Node *dup = new Node(cur->val, NULL, NULL);
        dup->next = cur->next;
        cur->next = dup;
        cur = dup->next;
    }

    cur = head;
    while (cur)
    {
        if (cur->random)
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    cur = head;
    Node *res = head->next;
    Node *tmp = res;
    while (cur)
    {
        cur->next = cur->next->next;
        cur = cur->next;
        if(tmp->next)
            tmp->next = tmp->next->next;
        tmp = tmp->next;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    // Node *n1 = new Node();
    // n1->val = 1;
    // Node *n2 = new Node();
    // n2->val = 2;
    // n1->next = n2;
    // n1->random = n2;
    // n2->next = NULL;
    // n2->random = n2;
    Node *n1 = new Node(-1);

    Node *res = copyRandomList(n1);
    while (res)
    {
        cout << res->val << " ";
        if (res->random)
            cout << res->random->val << " ";
        cout << endl;
        res = res->next;
    }
    return 0;
}
