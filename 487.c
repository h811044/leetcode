// 487. Max Consecutive Ones II

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int longestSequence = 0;
    int left = 0;
    int right = 0;
    int numZeroes = 0;

    while (right < numsSize) {
        if (nums[right] == 0) {
            numZeroes++;
        }
        while (numZeroes == 2) {
            if (nums[left] == 0) {
                numZeroes--;
            }
            left++;
        }
        int len = right - left + 1;
        longestSequence = len > longestSequence ? len : longestSequence;
        right++;
    }
    return longestSequence;
}
