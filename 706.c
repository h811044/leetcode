// 706. Design HashMap

typedef struct node {
    int key;
    int val;
    struct node *next;
} HashMapNode;

typedef struct {
    HashMapNode **bucketArray;
    int bucketNum;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap *)malloc(sizeof(MyHashMap));
    obj->bucketNum = 2069;
    obj->bucketArray = (HashMapNode **)calloc(obj->bucketNum, sizeof(HashMapNode *));
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int i = key % obj->bucketNum;
    HashMapNode *curr = obj->bucketArray[i];
    while (curr) {
        if (curr->key == key) {
            curr->val = value;
            return;
        }
        curr = curr->next;
    }
    HashMapNode *toAdd = (HashMapNode *)malloc(sizeof(HashMapNode));
    toAdd->key = key;
    toAdd->val = value;
    toAdd->next = obj->bucketArray[i];
    obj->bucketArray[i] = toAdd;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int i = key % obj->bucketNum;
    HashMapNode *curr = obj->bucketArray[i];
    while (curr) {
        if (curr->key == key) {
            return curr->val;
        }
        curr = curr->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int i = key % obj->bucketNum;
    HashMapNode *curr = obj->bucketArray[i];
    if (!curr) {
        return;
    }
    if (curr->key == key) {
        HashMapNode *toRemove = curr;
        obj->bucketArray[i] = curr->next;
        free(toRemove);
        return;
    }
    while (curr->next) {
        if (curr->next->key == key) {
            HashMapNode *toRemove = curr->next;
            curr->next = curr->next->next;
            free(toRemove);
            return;
        }
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < obj->bucketNum; i++) {
        HashMapNode *curr = obj->bucketArray[i];
        while (curr) {
            HashMapNode *toRemove = curr;
            curr = curr->next;
            free(toRemove);
        }
    }
    free(obj->bucketArray);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/
