// 707. Design Linked List

typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *head, *tail;
    head = (MyLinkedList *)malloc(sizeof(MyLinkedList) * 2);
    tail = head + 1;

    head->val = 0;
    head->next = tail;
    head->prev = tail;
    tail->val = 0;
    tail->next = head;
    tail->prev = head;

    return head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (obj == NULL) {
        return -1;
    }
    if (index < 0 || index >= obj->val) {
        return -1;
    }

    MyLinkedList *curr = obj;
    if ((index + 1) < (1 + obj->val - index)) {
        int step = index + 1;
        for (int i = 0; i < step; i++) {
            curr = curr->next;
        }
    } else {
        int step = 1 + obj->val - index;
        for (int i = 0; i < step; i++) {
            curr = curr->prev;
        }
    }

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj == NULL) {
        return;
    }

    MyLinkedList *toAdd;
    toAdd = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    toAdd->val = val;
    toAdd->next = obj->next;
    toAdd->prev = obj;

    toAdd->next->prev = toAdd;
    obj->next = toAdd;

    obj->val++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj == NULL) {
        return;
    }

    MyLinkedList *toAdd;
    toAdd = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    toAdd->val = val;
    toAdd->next = obj->prev;
    toAdd->prev = obj->prev->prev;

    obj->prev->prev = toAdd;
    toAdd->prev->next = toAdd;

    obj->val++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (obj == NULL) {
        return;
    }
    if (index > obj->val) {
        return;
    }
    if (index < 0) {
        index = 0;
    }

    // curr is the predecessor of toAdd
    MyLinkedList *curr = obj;
    if ((index + 1) < (1 + obj->val - index)) {
        int step = index + 1;
        for (int i = 0; i < step; i++) {
            curr = curr->next;
        }
    } else {
        int step = 1 + obj->val - index;
        for (int i = 0; i < step; i++) {
            curr = curr->prev;
        }
    }

    MyLinkedList *toAdd;
    toAdd = (MyLinkedList *)malloc(sizeof(MyLinkedList));

    toAdd->val = val;
    toAdd->next = curr;
    toAdd->prev = curr->prev;

    curr->prev = toAdd;
    toAdd->prev->next = toAdd;

    obj->val++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj == NULL) {
        return;
    }
    if (index < 0 || index >= obj->val) {
        return;
    }

    MyLinkedList *curr = obj;
    if ((index + 1) < (1 + obj->val - index)) {
        int step = index + 1;
        for (int i = 0; i < step; i++) {
            curr = curr->next;
        }
    } else {
        int step = 1 + obj->val - index;
        for (int i = 0; i < step; i++) {
            curr = curr->prev;
        }
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    obj->val--;

    free(curr);
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj == NULL) {
        return;
    }

    MyLinkedList *curr = obj->next;
    for (int i = 0; i < obj->val; i++) {
        MyLinkedList *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
