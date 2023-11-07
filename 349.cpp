// 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        for (int num : nums1) {
            hashset.insert(num);
        }

        vector<int> output;
        for (int num : nums2) {
            if (hashset.count(num) > 0) {
                output.push_back(num);
                hashset.erase(num);
            }
        }
        return output;
    }
};
