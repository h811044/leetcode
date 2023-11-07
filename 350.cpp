// 350. Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int num : nums1) {
            hashmap[num]++;
        }

        vector<int> output;
        for (int num : nums2) {
            if (hashmap.count(num) > 0) {
                output.push_back(num);
                if (--hashmap[num] == 0) {
                    hashmap.erase(num);
                }
            }
        }
        return output;
    }
};
