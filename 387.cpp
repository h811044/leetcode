// 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); i++) {
            hashmap[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (hashmap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
