// 704. Binary Search

int search(int* nums, int numsSize, int target) {
    // upper_bound
    int left = 0, right = numsSize;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (left > 0 && nums[left - 1] == target) {
        return left - 1;
    } else {
        return -1;
    } 
}
