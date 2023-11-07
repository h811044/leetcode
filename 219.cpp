// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashset;
        for (int i = 0; i <= k && i < nums.size(); i++) {
            if (hashset.count(nums[i]) > 0) {
                return true;
            }
            hashset.insert(nums[i]);
        }
        for (int i = 0, j = k + 1; j < nums.size(); i++, j++) {
            hashset.erase(nums[i]);
            if (hashset.count(nums[j]) > 0) {
                return true;
            }
            hashset.insert(nums[j]);
        }
        return false;
    }
};
