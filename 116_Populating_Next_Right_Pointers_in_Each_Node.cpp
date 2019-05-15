/** 问题描述：
 *  给定一个完全二叉树，所有的叶节点都在同一层上，每个父节点都有两个子节点。
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
        先把root的左右节点压入队列d。
        遍历所有d，设置一个start节点，将start->next指向每次出栈的tmp，除了第一个。
        每次都将tmp压入另一个队列level，保存每一层的所有节点。
        遍历所有level，将每个节点的左右节点按顺序压入d。
    */
   
    if (!root)
        return 0;
    Node *res = root;
    if (!root->left)
        return res;
    deque<Node*> d;
    d.push_back(root->left);
    d.push_back(root->right);
    while (d.size() != 0)
    {
        deque<Node*> level;
        Node *start = NULL;
        while (d.size() != 0)
        {
            Node *tmp = d.front();
            d.pop_front();
            level.push_back(tmp);
            if (!start)
            {
                start = tmp;
            }
            else
            {
                start->next = tmp;
                start = tmp;
            }
        }

        while (level.size() != 0)
        {
            Node *temp = level.front();
            level.pop_front();
            if (temp->left)
            {
                d.push_back(temp->left);
                d.push_back(temp->right);
            }
            else
            {
                break;
            }
        }
    }
    return res;
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
            cout << "(NULL) ";

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
    // Node *n1 = new Node(1, new Node(2, new Node(4, NULL, NULL, NULL), new Node(5, NULL, NULL, NULL), NULL), new Node(3, new Node(6, NULL, NULL, NULL), new Node(7, NULL, NULL, NULL), NULL));
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    traversalNodes(n1);
    cout << endl;
    Node *res = connect(n1);
    traversalNodes(res);
    return 0;
}
