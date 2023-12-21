// 378. Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        for (int i = 0; i < k && i < n; i++) {
            minHeap.push(make_tuple(matrix[i][0], i, 0));
        }

        for (int i = 0; i < k - 1; i++) {
            tuple<int, int, int> t = minHeap.top();
            int a = get<1>(t);
            int b = get<2>(t);
            int bInc = b + 1;
            if (bInc < n) {
                minHeap.push(make_tuple(matrix[a][bInc], a, bInc));
            }
            minHeap.pop();
        }

        return get<0>(minHeap.top());
    }
};
