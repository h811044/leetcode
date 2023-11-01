// 54. Spiral Matrix

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *returnArr;

    *returnSize = matrixSize * matrixColSize[0];
    returnArr = (int *)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    int j = -1;
    int iStep = matrixSize - 1;
    int jStep = matrixColSize[0];
    int k = 0;
    while (1) {
        for (int m = 0; m < jStep; m++) {
            j++;
            returnArr[k++] = matrix[i][j];
        }
        if (k == *returnSize) {
            break;
        }
        jStep--;
        for (int m = 0; m < iStep; m++) {
            i++;
            returnArr[k++] = matrix[i][j];
        }
        if (k == *returnSize) {
            break;
        }
        iStep--;
        for (int m = 0; m < jStep; m++) {
            j--;
            returnArr[k++] = matrix[i][j];
        }
        if (k == *returnSize) {
            break;
        }
        jStep--;
        for (int m = 0; m < iStep; m++) {
            i--;
            returnArr[k++] = matrix[i][j];
        }
        if (k == *returnSize) {
            break;
        }
        iStep--;
    }

    return returnArr;
}
