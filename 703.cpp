// 703. Kth Largest Element in a Stream

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    bool full;

public:
    KthLargest(int k, vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        while (i < k && i < size) {
            heap.push(nums[i]);
            i++;
        }
        full = (heap.size() == k);
        while (i < size) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
            i++;
        }
        return;
    }

    int add(int val) {
        if (!full) {
            heap.push(val);
            full = true;
        } else if (val > heap.top()) {
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
