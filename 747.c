// 747. Largest Number At Least Twice of Others

int dominantIndex(int* nums, int numsSize){
    int m;
    int maxIndex;
    int m2;

    if (nums[0] > nums[1]) {
        m = nums[0];
        maxIndex = 0;
        m2 = nums[1];
    } else {
        m = nums[1];
        maxIndex = 1;
        m2 = nums[0];
    }

    for (int i = 2; i < numsSize; i++) {
        if (nums[i] > m) {
            m2 = m;
            m = nums[i];
            maxIndex = i;
        } else if (nums[i] > m2) {
            m2 = nums[i];
        }
    }

    return m >= 2 * m2 ? maxIndex : -1;
}
