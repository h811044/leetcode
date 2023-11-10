// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
        vector<int> squareNums;
        for (int i = 1; i * i <= n; i++) {
            squareNums.push_back(i * i);
        }

        unordered_map<int, int> hashmap;    // DP <sum, step>
        queue<int> q;
        hashmap[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int sum = q.front();
            q.pop();
            int step = hashmap[sum] + 1;
            for (int s : squareNums) {
                int newSum = sum + s;
                if (newSum == n) {
                    return step;
                } else if (newSum < n) {
                    if (hashmap.count(newSum) <= 0) {
                        hashmap[newSum] = step;
                        q.push(newSum);
                    }
                }
            }
        }

        return -1;
    }
};
