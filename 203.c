// 203. Remove Linked List Elements

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode sentinel;
    sentinel.next = head;

    struct ListNode *curr = &sentinel;
    while (curr->next) {
        if (curr->next->val == val) {
            struct ListNode *toDelete = curr->next;
            curr->next = curr->next->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
    return sentinel.next;
}
