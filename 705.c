// 705. Design HashSet

typedef struct node {
    int val;
    struct node *next;
} HashSetNode;

typedef struct {
    HashSetNode **bucketArray;
    int bucketNum;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    obj->bucketNum = 769;
    obj->bucketArray = (HashSetNode **)calloc(obj->bucketNum, sizeof(HashSetNode *));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int i = key % obj->bucketNum;
    HashSetNode *curr = obj->bucketArray[i];
    while (curr) {
        if (curr->val == key) {
            return;
        }
        curr = curr->next;
    }
    HashSetNode *toAdd = (HashSetNode *)malloc(sizeof(HashSetNode));
    toAdd->val = key;
    toAdd->next = obj->bucketArray[i];
    obj->bucketArray[i] = toAdd;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int i = key % obj->bucketNum;
    HashSetNode *curr = obj->bucketArray[i];
    if (!curr) {
        return;
    }
    if (curr->val == key) {
        HashSetNode *toRemove = curr;
        obj->bucketArray[i] = curr->next;
        free(toRemove);
        return;
    }
    while (curr->next) {
        if (curr->next->val == key) {
            HashSetNode *toRemove = curr->next;
            curr->next = curr->next->next;
            free(toRemove);
            return;
        }
        curr = curr->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int i = key % obj->bucketNum;
    HashSetNode *curr = obj->bucketArray[i];
    while (curr) {
        if (curr->val == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < obj->bucketNum; i++) {
        HashSetNode *curr = obj->bucketArray[i];
        while (curr) {
            HashSetNode *toRemove = curr;
            curr = curr->next;
            free(toRemove);
        }
    }
    free(obj->bucketArray);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
