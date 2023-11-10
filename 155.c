// 155. Min Stack

typedef struct node {
    int val;
    struct node *next;
} StackNode;

typedef struct {
    StackNode *top;
    StackNode *min;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->top = NULL;
    obj->min = NULL;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    StackNode *toAdd = (StackNode *)malloc(sizeof(StackNode));
    toAdd->val = val;
    toAdd->next = obj->top;
    obj->top = toAdd;

    if (obj->min == NULL || val <= obj->min->val) {
        toAdd = (StackNode *)malloc(sizeof(StackNode));
        toAdd->val = val;
        toAdd->next = obj->min;
        obj->min = toAdd;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == NULL) {
        return;
    }

    if (obj->min->val == obj->top->val) {
        StackNode *toRemove = obj->min;
        obj->min = obj->min->next;
        free(toRemove);
    }

    StackNode *toRemove = obj->top;
    obj->top = obj->top->next;
    free(toRemove);
}

int minStackTop(MinStack* obj) {
    if (obj->top == NULL) {
        return -1;
    }

    return obj->top->val;
}

int minStackGetMin(MinStack* obj) {
    if (obj->top == NULL) {
        return -1;
    }

    return obj->min->val;
}

void minStackFree(MinStack* obj) {
    while (obj->top) {
        StackNode *toRemove = obj->top;
        obj->top = obj->top->next;
        free(toRemove);
    }
    while (obj->min) {
        StackNode *toRemove = obj->min;
        obj->min = obj->min->next;
        free(toRemove);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
