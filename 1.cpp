// 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hashmap.count(complement) > 0) {
                return {hashmap[complement], i};
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return {};
    }
};
