// 286. Walls and Gates

class Solution {
    int di[4] = {-1, 0, 1,  0};
    int dj[4] = { 0, 1, 0, -1};

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();
        queue<tuple<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push(make_tuple(i, j));
                }
            }
        }

        while (!q.empty()) {
            int i;
            int j;
            tie(i, j) = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int newi = i + di[dir];
                int newj = j + dj[dir];
                if (newi < 0 || newi >= m || newj < 0 || newj >= n) {
                    continue;
                }
                if (rooms[newi][newj] == 2147483647) {
                    rooms[newi][newj] = rooms[i][j] + 1;
                    q.push(make_tuple(newi, newj));
                }
            }
        }
    }
};
