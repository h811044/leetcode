// 739. Daily Temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(), 0);
        stack<tuple<int, int>> s;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty()) {
                int val, pos;
                tie(val, pos) = s.top();
                if (val > temperatures[i]) {
                    v[i] = pos - i;
                    s.push(make_tuple(temperatures[i], i));
                    break;
                }
                s.pop();
            }
            if (s.empty()) {
                v[i] = 0;
                s.push(make_tuple(temperatures[i], i));
            }
        }

        return v;
    }
};
