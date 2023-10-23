// 414. Third Maximum Number

int thirdMax(int* nums, int numsSize){
    int max[3];
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if ((count >= 1 && max[0] == nums[i])
                || (count >= 2 && max[1] == nums[i])
                || (count >= 3 && max[2] == nums[i])) {
            continue;
        }

        if (count < 1 || nums[i] > max[0]) {
            max[2] = max[1];
            max[1] = max[0];
            max[0] = nums[i];
            count++;
        } else if (count < 2 || nums[i] > max[1]) {
            max[2] = max[1];
            max[1] = nums[i];
            count++;
        } else if (count < 3 || nums[i] > max[2]) {
            max[2] = nums[i];
            count++;
        }
    }

    if (count < 3) {
        return max[0];
    }

    return max[2];
}
