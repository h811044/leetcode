// 599. Minimum Index Sum of Two Lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        for (int i = 0; i < list1.size(); i++) {
            hashmap[list1[i]] = i;
        }
        vector<string> res;
        int minSum = list1.size() + list2.size();
        for (int i = 0; i < list2.size() && i <= minSum; i++) {
            if (hashmap.count(list2[i]) > 0) {
                int sum = i + hashmap[list2[i]];
                if (sum == minSum) {
                    res.push_back(list2[i]);
                } else if (sum < minSum) {
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = sum;
                }
            }
        }
        return res;
    }
};
