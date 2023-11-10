// 200. Number of Islands

class Solution {
    int di[4] = {-1, 0, 1,  0};
    int dj[4] = { 0, 1, 0, -1};

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<tuple<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '2';
                    q.push(make_tuple(i, j));
                    count++;
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
                        if (grid[newi][newj] == '1') {
                            grid[newi][newj] = '2';
                            q.push(make_tuple(newi, newj));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '2') {
                    grid[i][j] == '1';
                }
            }
        }

        return count;
    }
};
