// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int i = 0;
        while (i < k) {
            heap.push(nums[i]);
            i++;
        }
        int size = nums.size();
        while (i < size) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
            i++;
        }
        return heap.top();
    }
};
