// 138. Copy List with Random Pointer

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return head;
    }

    struct Node *ptr = head;
    while (ptr) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = ptr->val;
        newNode->next = ptr->next;
        ptr->next = newNode;
        ptr = newNode->next;
    }

    ptr = head;
    while (ptr) {
        ptr->next->random = ptr->random ? ptr->random->next : NULL;
        ptr = ptr->next->next;
    }

    ptr = head;
    struct Node *newPtr = ptr->next;
    struct Node *newHead = head->next;
    while (ptr) {
        ptr->next = ptr->next->next;
        newPtr->next = ptr->next ? newPtr->next->next : NULL;
        ptr = ptr->next;
        newPtr = newPtr->next;
    }

    return newHead;
}
