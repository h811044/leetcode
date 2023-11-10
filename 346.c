// 346. Moving Average from Data Stream

typedef struct {
    int *queue;
    int size;
    int head;
    int windowSum;
    int count;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage *obj = (MovingAverage *)malloc(sizeof(MovingAverage));
    obj->queue = (int *)malloc(sizeof(int) * size);
    obj->size = size;
    obj->head = 0;
    obj->windowSum = 0;
    obj->count = 0;
    return obj;
}

double movingAverageNext(MovingAverage* obj, int val) {
    if (obj->count == obj->size) {
        obj->windowSum = obj->windowSum - obj->queue[obj->head] + val;
        obj->queue[obj->head] = val;
        obj->head = (obj->head + 1) % obj->size;
    } else {
        obj->windowSum += val;
        obj->queue[obj->head] = val;
        obj->head = (obj->head + 1) % obj->size;
        obj->count++;
    }
    return obj->windowSum * 1.0 / obj->count;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/
