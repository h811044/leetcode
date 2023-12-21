// 973. K Closest Points to Origin

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    int dist[pointsSize];
    for (int i = 0; i < pointsSize; i++) {
        dist[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    
    int rank[pointsSize];
    for (int i = 0; i < pointsSize; i++) {
        rank[i] = i;
    }

    int found = 0;
    int spaceS = 0, spaceE = pointsSize - 1;
    while (found < k) {
        int h = spaceS, t = spaceE;
        int pivot = spaceS + rand() % (spaceE - spaceS + 1);
        int pivotDist = dist[rank[pivot]];
        while (h < t) {
            while (h <= t && dist[rank[h]] <= pivotDist) {
                h++;
            }
            while (h <= t && dist[rank[t]] > pivotDist) {
                t--;
            }
            if (h < t) {
                int temp = rank[h];
                rank[h] = rank[t];
                rank[t] = temp;
            }
        }
        if (found + h - spaceS > k) {
            spaceE = t;
        } else {
            found = found + h - spaceS;
            spaceS = h;
        }
    }

    int **returnPoints = (int **)malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++) {
        returnPoints[i] = (int *)malloc(sizeof(int) * pointsColSize[0]);
        returnPoints[i][0] = points[rank[i]][0];
        returnPoints[i][1] = points[rank[i]][1];
    }
    *returnSize = k;
    *returnColumnSizes = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = pointsColSize[0];
    }
    return returnPoints;
}
