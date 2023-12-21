// 542. 01 Matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> returnMat(m, vector<int>(n, 0));
        queue<tuple<int, int>> q;

        int large = m + n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    returnMat[i][j] = large;
                } else {
                    q.push(make_tuple(i, j));
                }
            }
        }

        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            q.pop();
            int val = returnMat[i][j] + 1;

            for (vector<int>& d : dir) {
                int di = i + d[0];
                int dj = j + d[1];
                if (0 <= di && di < m && 0 <= dj && dj < n) {
                    if (returnMat[di][dj] > val) {
                        returnMat[di][dj] = val;
                        q.push(make_tuple(di, dj));
                    }
                }
            }
        }

        return returnMat;
    }
};
