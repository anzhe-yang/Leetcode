/** 问题描述：
 *  给定一个连接好的无向图中节点的引用，返回图的克隆。
 *  图中每个点都包含其邻居的值和列表。
 *  节点值在 1-100 之间。
 *  图中没有重复的节点值。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node 
{
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> clone;

Node* cloneGraph(Node* node)
{
    /*
        DFS
        每次遍历map里最后的节点，将此节点的所有neighbors压入map当前node的value值中，对应的key为node值。
    */

    // if (!node)
    //     return NULL;
    // if (clone.find(node) == clone.end())
    // {
    //     clone[node] = new Node(node->val, {});
    //     for (Node *neighbor : node->neighbors)
    //     {
    //         clone[node]->neighbors.push_back(cloneGraph(neighbor));
    //     }
    // }
    // return clone[node];

    /*
        BFS
        为了防止广度优先遍历重复遍历某个节点，建立一个队列变量todo，保存已遍历过的节点。
        遍历其中每个节点，将它的neighbors压入map里cur值对应的value中。
        其中首先判断clone这个map变量是否保存过这个节点，如果没有，再进行压入操作，防止重复压入。
    */

    if (!node)
        return NULL;
    clone[node] = new Node(node->val, {});
    queue<Node*> todo;
    todo.push(node);
    while (!todo.empty())
    {
        Node* cur = todo.front();
        todo.pop();
        for (Node *neighbor : cur->neighbors)
        {
            if (clone.find(neighbor) == clone.end())
            {
                clone[neighbor] = new Node(neighbor->val, {});
                todo.push(neighbor);
            }
            clone[cur]->neighbors.push_back(clone[neighbor]);
        }
    }
    return clone[node];
}

int main(int argc, char const *argv[])
{
    Node *n1 = new Node(1, {});
    Node *n2 = new Node(2, {});
    Node *n3 = new Node(3, {});
    Node *n4 = new Node(4, {});
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n1->neighbors.push_back(n4);

    Node *res = cloneGraph(n1);
    for (Node *node : res->neighbors)
    {
        cout << node->val << endl;
    }
    return 0;
}

// {"$id":"1","neighbors":[{"$id":"2","neighbors":[
//     {"$ref":"1"},{"$id":"3","neighbors":
//     [{"$ref":"2"},{"$id":"4","neighbors":
//     [{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}