// 841. Keys and Rooms

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> hashset;
        hashset.insert(0);
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : rooms[i]) {
                if (hashset.count(j) <= 0) {
                    hashset.insert(j);
                    q.push(j);
                }
            }
        }
        return hashset.size() == rooms.size();
    }
};
