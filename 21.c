// 21. Merge Two Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *p1 = list1;
    struct ListNode *p2 = list2;
    struct ListNode sentinel;
    struct ListNode *tail = &sentinel;

    sentinel.next = NULL;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        } else {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }
    if (p1) {
        tail->next = p1;
    } else if (p2) {
        tail->next = p2;
    }
    return sentinel.next;
}
