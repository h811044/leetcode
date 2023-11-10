// 622. Design Circular Queue

typedef struct {
    int *queue;
    int headIndex;
    int count;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->queue = (int *)malloc(sizeof(int) * k);
    obj->headIndex = 0;
    obj->count = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->count == obj->capacity) {
        return false;
    }
    obj->queue[(obj->headIndex + obj->count) % obj->capacity] = value;
    obj->count++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->count == 0) {
        return false;
    }
    obj->headIndex = (obj->headIndex + 1) % obj->capacity;
    obj->count--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->count == 0) {
        return -1;
    }
    return obj->queue[obj->headIndex];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->count == 0) {
        return -1;
    }
    return obj->queue[(obj->headIndex + obj->count - 1) % obj->capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->count == 0) {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->count == obj->capacity) {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
