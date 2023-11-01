// 498. Diagonal Traverse

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int *returnArr;

    *returnSize = matSize * matColSize[0];
    returnArr = (int *)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    int j = 0;
    int di[6] = {-1, 0, 1,  1, 1, 0};
    int dj[6] = { 1, 1, 0, -1, 0, 1};
    int dir = 0;
    for (int k = 0; k < *returnSize; k++) {
        returnArr[k] = mat[i][j];
        switch (dir) {
            case 1:
            case 2:
            case 3:
                if (i == matSize - 1 || j == 0) {
                    dir = i + 1 < matSize ? 4 : 5;
                } else {
                    dir = 3;
                }
                break;
            case 4:
            case 5:
            case 0:
                if (i == 0 || j == matColSize[0] - 1) {
                    dir = j + 1 < matColSize[0] ? 1 : 2;
                } else {
                    dir = 0;
                }
                break;
        }
        i += di[dir];
        j += dj[dir];
    }

    return returnArr;
}
