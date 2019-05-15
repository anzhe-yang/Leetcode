/** 问题描述：
 *  给定一个二叉树。
 *  数据结构中的 next 指向它的右节点，如果不存在，则指向 NULL 。
 *  初始化时，所有的 next 都指向 NULL 。
 */

#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    // Node() {}
    Node(int x) : val(x) ,left(NULL), right(NULL), next(NULL) {} 

    // Node(int _val, Node* _left, Node* _right, Node* _next) 
    // {
    //     val = _val;
    //     left = _left;
    //     right = _right;
    //     next = _next;
    // }
};

Node* connect(Node* root)
{
    /*
        先把root节点压入队列d。
        遍历所有d，将队列的front赋给tmp，弹出一个。
        如果弹出tmp后，d还不为空，那么tmp->next指向d的front，否则指向NULL。
        每次都将tmp压入另一个队列level，保存每一层的所有节点。
        遍历所有level，将每个节点的左右节点按顺序压入d。
    */
   
    if (!root)
        return 0;
    Node *res = root;
    deque<Node*> d;
    d.push_back(root);
    while (d.size() != 0)
    {
        deque<Node*> level;
        while (d.size() != 0)
        {
            Node *tmp = d.front();
            d.pop_front();
            level.push_back(tmp);
            tmp->next = d.empty() ? NULL : d.front();
        }

        while (level.size() != 0)
        {
            Node *temp = level.front();
            level.pop_front();
            if (temp->left)
                d.push_back(temp->left);
            if (temp->right)
                d.push_back(temp->right);
        }
    }
    return res;

    /*
        start表示下一层的第一个节点。
        preNode表示前一个节点。
        cur表示当前节点。
        判断当前节点的左右子节点，将start与preNode进行更新。
        判断完当前节点后，指向下一节点。
        如果没有，则表示当前层工作完毕，指向下一层的头节点，即start。
        之后将start和preNode清零，进行下一层工作。
    */

    // Node *start = NULL;
    // Node *preNode = NULL;
    // Node *cur = root;
    // while (cur)
    // {
    //     while (cur)
    //     {
    //         if (cur->left)
    //         {
    //             if (preNode)
    //             {
    //                 preNode->next = cur->left;
    //             }
    //             else
    //             {
    //                 start = cur->left;
    //             }
    //             preNode = cur->left;
    //         }
    //         if (cur->right)
    //         {
    //             if (preNode)
    //             {
    //                 preNode->next = cur->right;
    //             }
    //             else
    //             {
    //                 start = cur->right;
    //             }
    //             preNode = cur->right;
    //         }
    //         cur = cur->next;
    //     }

    //     cur = start;
    //     start = NULL;
    //     preNode = NULL;
    // }
    // return root;
}

void traversalNodes(Node* tree)
{
    deque<Node*> d;
    d.push_back(tree);
    int printedNum = 1;
    int nextLevelNum = 0;
    while (!d.empty())
    {
        Node *temp = d.front();
        d.pop_front();
        cout << temp->val;
        printedNum--;
        if (temp->next)
            cout << "(->" << temp->next->val << ") ";
        else
            cout << "(->NULL) ";

        if (temp->left)
        {
            d.push_back(temp->left);
            nextLevelNum++;
        }

        if (temp->right)
        {
            d.push_back(temp->right);
            nextLevelNum++;
        }

        if (printedNum == 0)
        {
            cout << endl;
            printedNum = nextLevelNum;
            nextLevelNum = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n7 = new Node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n7;

    traversalNodes(n1);
    cout << endl;
    Node *res = connect(n1);
    traversalNodes(res);
    return 0;
}
