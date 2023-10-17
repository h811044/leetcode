// 27. Remove Element

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int j = numsSize - 1;

    while (i <= j) {
        if (nums[i] == val) {
            if (nums[j] == val) {
                j--;
            } else {
                nums[i] = nums[j];
                i++;
                j--;
            }
        } else {
            i++;
        }
    }
    return i;
}
