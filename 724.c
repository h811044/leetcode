// 724. Find Pivot Index

int pivotIndex(int* nums, int numsSize){
    int index = -1;
    int rightsum = 0;
    for (int i = 0; i < numsSize; i++) {
        rightsum += nums[i];
    }
    int leftsum = 0;
    for (int i = 0; i < numsSize; i++) {
        rightsum -= nums[i];
        if (leftsum == rightsum) {
            index = i;
            break;
        }
        leftsum += nums[i];
    }
    return index;
}
