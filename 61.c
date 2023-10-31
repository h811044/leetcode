// 61. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int n = 0;
    struct ListNode *ptr = head;
    while (ptr->next) {
        n++;
        ptr = ptr->next;
    }
    ptr->next = head;
    n++;
    ptr = ptr->next;

    for (int i = 0; i < n - 1 - k % n; i++) {
        ptr = ptr->next;
    }

    struct ListNode *newHead = ptr->next;
    ptr->next = NULL;

    return newHead;
}
