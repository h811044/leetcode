// 217. Contains Duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num : nums) {
            if (hashset.count(num) > 0) {
                return true;
            }
            hashset.insert(num);
        }
        return false;
    }
};
