// 133. Clone Graph

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return node;
        }
        unordered_map<Node *, Node *> hashmap;
        queue<Node *> q;

        Node *newNode = new Node(node->val, node->neighbors);
        hashmap[node] = newNode;
        q.push(newNode);

        while (!q.empty()) {
            Node *n = q.front();
            q.pop();
            for (Node *&neighbor : n->neighbors) {
                if (hashmap.count(neighbor) <= 0) {
                    Node *newNeighbor = new Node(neighbor->val, neighbor->neighbors);
                    hashmap[neighbor] = newNeighbor;
                    q.push(newNeighbor);
                }
                neighbor = hashmap[neighbor];
            }
        }

        return newNode;
    }
};
