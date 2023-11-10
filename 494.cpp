// 494. Target Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        queue<pair<int, int>> q;
        unordered_map<int, int> hashmap;
        int size = nums.size();

        q.push(make_pair(0, 1));
        for (int i = 0; i < size; i++) {
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int newVal = p.first + nums[i];
                hashmap[newVal] += p.second;
                newVal = p.first - nums[i];
                hashmap[newVal] += p.second;
            }
            for (pair<int, int> p : hashmap) {
                q.push(p);
            }
            hashmap.clear();
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first == target) {
                return p.second;
            }
        }
        return 0;
    }
};
