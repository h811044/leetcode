// 905. Sort Array By Parity

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *returnNums;
    int l = 0, r = numsSize - 1;

    returnNums = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            returnNums[l] = nums[i];
            l++;
        } else {
            returnNums[r] = nums[i];
            r--;
        }
    }

    return returnNums;
}
