// 283. Move Zeroes

void moveZeroes(int* nums, int numsSize){
    int insertIndex = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    while (insertIndex < numsSize) {
        nums[insertIndex] = 0;
        insertIndex++;
    }
}
