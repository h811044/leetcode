// 708. Insert into a Sorted Circular Linked List

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 * };
 */

struct Node* insert(struct Node* head, int insertVal) {
    struct Node *insertNode;
    struct Node *curr = head;

    insertNode = (struct Node *)malloc(sizeof(struct Node));
    insertNode->val = insertVal;

    if (head) {
        do {
            if (curr->val > curr->next->val) {
                if (curr->val <= insertVal || insertVal <= curr->next->val) {
                    break;
                }
            } else if (curr->val <= insertVal && insertVal <= curr->next->val) {
                break;
            }
            curr = curr->next;
        } while (curr != head);
        insertNode->next = curr->next;
        curr->next = insertNode;
    } else {
        head = insertNode;
        insertNode->next = head;
    }

    return head;
}
