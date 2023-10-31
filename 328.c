// 328. Odd Even Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *heads[2] = {head, head->next};
    struct ListNode *tails[2] = {head, head->next};
    struct ListNode *curr = head->next->next;
    int i = 0;

    while (curr) {
        tails[i]->next = curr;
        tails[i] = curr;
        curr = curr->next;
        i = !i;
    }
    tails[0]->next = heads[1];
    tails[1]->next = NULL;
    return heads[0];
}
