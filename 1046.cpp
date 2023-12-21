// 1046. Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int stone : stones) {
            heap.push(stone);
        }

        while (heap.size() > 1) {
            int stone1 = heap.top();
            heap.pop();
            int stone2 = heap.top();
            heap.pop();
            if (stone1 != stone2) {
                heap.push(stone1 - stone2);
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};
