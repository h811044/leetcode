// 752. Open the Lock

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int graph[10][10][10][10] = {0};
        graph[target[0] - '0'][target[1] - '0'][target[2] - '0'][target[3] - '0'] = -1;
        if (graph[0][0][0][0] == -1) {
            return 0;
        }
        for (string d : deadends) {
            graph[d[0] - '0'][d[1] - '0'][d[2] - '0'][d[3] - '0'] = -2;
        }
        if (graph[0][0][0][0] == -2) {
            return -1;
        }

        queue<tuple<int, int, int, int>> q;
        q.push(make_tuple(0, 0, 0, 0));

        while (!q.empty()) {
            int i[4];
            tie(i[0], i[1], i[2], i[3]) = q.front();
            q.pop();

            int depth = graph[i[0]][i[1]][i[2]][i[3]] + 1;
            for (int d = 0; d < 4; d++) {
                int origd = i[d];
                i[d] = (origd + 1) % 10;
                if (graph[i[0]][i[1]][i[2]][i[3]] == 0) {
                    graph[i[0]][i[1]][i[2]][i[3]] = depth;
                    q.push(make_tuple(i[0], i[1], i[2], i[3]));
                } else if (graph[i[0]][i[1]][i[2]][i[3]] == -1) {
                    return depth;
                }
                i[d] = (origd - 1 + 10) % 10;
                if (graph[i[0]][i[1]][i[2]][i[3]] == 0) {
                    graph[i[0]][i[1]][i[2]][i[3]] = depth;
                    q.push(make_tuple(i[0], i[1], i[2], i[3]));
                } else if (graph[i[0]][i[1]][i[2]][i[3]] == -1) {
                    return depth;
                }
                i[d] = origd;
            }
        }

        return -1;
    }
};
