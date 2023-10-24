// 19. Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *p1 = &dummy;
    struct ListNode *p2 = &dummy;

    for (int i = 0; i < n; i++) {
        p2 = p2->next;
    }
    while (p2->next) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;

    return dummy.next;
}
