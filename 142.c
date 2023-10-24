// 142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *tortoise = head;
    struct ListNode *hare = head;

    while (hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            break;
        }
    }

    if (!hare || !hare->next) {
        return NULL;
    }

    // Let's define a as the length of the path from the start of the list
    //      to the entrance of the cycle.
    // Let's define b as the length of the path from the cycle's entrance 
    //      to the meeting point of the hare and the tortoise inside the cycle.
    // Let's define c as the total length of the cycle.

    // tortoise is (a + b) = (k * c) steps ahead of hare
    hare = head;

    while (tortoise != hare) {      // after a steps
        tortoise = tortoise->next;  // a + (k * c)
        hare = hare->next;          // a
    }

    return tortoise;
}
