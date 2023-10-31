// 234. Palindrome Linked List

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while (curr) {
        struct ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

struct ListNode* endOfFirstHalf(struct ListNode* head){
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    if (head == NULL) {
        return true;
    }

    struct ListNode *firstHalfEnd = endOfFirstHalf(head);
    struct ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

    struct ListNode *p1 = head;
    struct ListNode *p2 = secondHalfStart;
    bool result = true;
    while (result && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    reverseList(secondHalfStart);
    return result;
}
