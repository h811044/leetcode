// 89. Gray Code

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int sz = 1 << n;
    *returnSize = sz;
    int *returnArr = (int *)malloc(sizeof(int) * sz);

    int i = 0;
    returnArr[i++] = 0;
    int newBit = 1;
    while (i < sz) {
        for (int j = i - 1; j >= 0; j--) {
            returnArr[i++] = returnArr[j] | newBit;
        }
        newBit <<= 1;
    }

    return returnArr;
}
