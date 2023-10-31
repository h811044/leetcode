// 430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        while (curr) {
            if (curr->child) {
                Node *tempNext = curr->next;
                curr->next = flatten(curr->child);
                curr->child = nullptr;
                curr->next->prev = curr;
                while (curr->next) {
                    curr = curr->next;
                }
                if (tempNext) {
                    curr->next = tempNext;
                    curr->next->prev = curr;
                }
                curr = tempNext;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
