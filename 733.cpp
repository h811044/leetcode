// 733. Flood Fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<tuple<int, int>> q;
        int origColor = image[sr][sc];
        if (origColor == color) {
            return image;
        }
        int maxI = image.size();
        int maxJ = image[0].size();
        q.push(make_tuple(sr, sc));
        while (!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            q.pop();
            if (image[i][j] == origColor) {
                image[i][j] = color;
                if (i - 1 >= 0) {
                    q.push(make_tuple(i - 1, j));
                }
                if (j + 1 < maxJ) {
                    q.push(make_tuple(i, j + 1));
                }
                if (i + 1 < maxI) {
                    q.push(make_tuple(i + 1, j));
                }
                if (j - 1 >= 0) {
                    q.push(make_tuple(i, j - 1));
                }
            }
        }
        return image;
    }
};
