// 448. Find All Numbers Disappeared in an Array

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *returnNums;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i] > 0 ? nums[i] : -nums[i];
        num = num - 1;
        if (nums[num] > 0) {
            nums[num] = -nums[num];
            count++;
        }
    }

    *returnSize = numsSize - count;
    returnNums = (int *)malloc(sizeof(int) * (*returnSize));

    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            returnNums[j] = i + 1;
            j++;
        } else {
            nums[i] = -nums[i];
        }
    }

    return returnNums;
}
