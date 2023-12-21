// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int num : nums) {
            hashmap[num]++;
        }

        int size = nums.size();
        vector<int> freq[size + 1];
        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            freq[it->second].push_back(it->first);
        }

        vector<int> v;
        int i = size;
        while (v.size() < k) {
            v.insert(v.end(), freq[i].begin(), freq[i].end());
            i--;
        }

        return v;
    }
};
