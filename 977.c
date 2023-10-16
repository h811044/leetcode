// 977. Squares of a Sorted Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *returnNums;
    int i, j;
    int k;
    int left, right;

    returnNums = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    i = 0;
    j = numsSize - 1;
    k = numsSize - 1;
    left = nums[i] * nums[i];
    right = nums[j] * nums[j];
    while (i < j) {
        if (left > right) {
            returnNums[k] = left;
            i++;
            left = nums[i] * nums[i];
        } else {
            returnNums[k] = right;
            j--;
            right = nums[j] * nums[j];
        }
        k--;
    }
    returnNums[k] = left;

    return returnNums;
}
