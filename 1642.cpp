// 1642. Furthest Building You Can Reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxHeap;
        int pos = 0;
        int last = heights.size() - 1;
        int diff;

        while (1) {
            while (pos < last) {
                diff = heights[pos + 1] - heights[pos];
                if (diff <= 0) {
                    pos++;
                } else {
                    if (bricks >= diff) {
                        bricks -= diff;
                        maxHeap.push(diff);
                        pos++;
                    } else {
                        break;
                    }
                }
            }

            if (pos < last && ladders > 0) {
                if (maxHeap.size() > 0) {
                    bricks -= diff;
                    maxHeap.push(diff);
                    bricks += maxHeap.top();
                    maxHeap.pop();
                }
                ladders--;
                pos++;
            } else {
                break;
            }
        }

        return pos;
    }
};
