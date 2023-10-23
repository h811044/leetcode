// 1051. Height Checker

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeapify(int* arr, int start, int end){
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if (arr[dad] > arr[son]) {
            return;
        } else {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapSort(int* arr, int len){
    for (int i = len / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, len - 1);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, 0, i - 1);
    }
}

int heightChecker(int* heights, int heightsSize){
    int expected[heightsSize];
    int mismatch = 0;

    for (int i = 0; i < heightsSize; i++) {
        expected[i] = heights[i];
    }

    heapSort(expected, heightsSize);

    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            mismatch++;
        }
    }

    return mismatch;
}
