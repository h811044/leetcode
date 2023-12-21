// 1167. Minimum Cost to Connect Sticks

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int s : sticks) {
            minHeap.push(s);
        }

        int sum = 0;
        while (minHeap.size() > 1) {
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            int c = a + b;
            sum += c;
            minHeap.push(c);
        }
        return sum;
    }
};
