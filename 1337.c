// 1337. The K Weakest Rows in a Matrix

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    *returnSize = k;
    int *returnArr = (int *)malloc(sizeof(int) * k);

    int m = matSize, n = matColSize[0];
    int l = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[j][i] == 0 && (i == 0 || mat[j][i - 1] == 1)) {
                returnArr[l++] = j;
                if (l == k) {
                    return returnArr;
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (mat[j][n - 1] == 1) {
            returnArr[l++] = j;
            if (l == k) {
                break;
            }
        }
    }
    return returnArr;
}
