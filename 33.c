// 33. Search in Rotated Sorted Array

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        // subarray on mid's left is sorted
        } else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid -1;
            } else {
                left = mid + 1;
            }
        // subarray on mid's right is sorted
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid -1;
            }
        }
    }
    return -1;
}
