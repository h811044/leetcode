// 1346. Check If N and Its Double Exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashset;
        for (int i : arr) {
            if (hashset.count(i * 2) > 0) {
                return true;
            }
            if (i % 2 == 0 && hashset.count(i / 2) > 0) {
                return true;
            }
            hashset.insert(i);
        }
        return false;
    }
};
