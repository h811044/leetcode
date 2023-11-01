// 118. Pascal's Triangle

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** returnMat;

    returnMat = (int **)malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        int *arr = (int *)malloc(sizeof(int) * (i + 1));

        arr[0] = 1;
        for (int j = 1; j < i; j++) {
            arr[j] = returnMat[i - 1][j - 1] + returnMat[i - 1][j];
        }
        arr[i] = 1;

        returnMat[i] = arr;
        (*returnColumnSizes)[i] = i + 1;
    }

    return returnMat;
}
