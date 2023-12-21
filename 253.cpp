// 253. Meeting Rooms II

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> minHeap;
        for (auto time : intervals) {
            minHeap.push(make_tuple(time[0], 1));
            minHeap.push(make_tuple(time[1], 0));
        }

        int room = 0;
        int maxRoom = 0;
        while (minHeap.size() > 0) {
            if (get<1>(minHeap.top())) {
                room++;
                maxRoom = room > maxRoom ? room : maxRoom;
            } else {
                room--;
            }
            minHeap.pop();
        }

        return maxRoom;
    }
};
