// 1299. Replace Elements with Greatest Element on Right Side

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int *returnArr;
    int max = -1;

    returnArr = (int *)malloc(sizeof(int) * arrSize);
    *returnSize = arrSize;

    for (int i = arrSize - 1; i >= 0; i--) {
        returnArr[i] = max;
        max = arr[i] > max ? arr[i] : max;
    }

    return returnArr;
}
