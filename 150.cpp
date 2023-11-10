// 150. Evaluate Reverse Polish Notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string t : tokens) {
            int res;
            if (t.compare("+") == 0) {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                res = o1 + o2;
            } else if (t.compare("-") == 0) {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                res = o1 - o2;
            } else if (t.compare("*") == 0) {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                res = o1 * o2;
            } else if (t.compare("/") == 0) {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                res = o1 / o2;
            } else {
                res = stoi(t);
            }
            s.push(res);
        }
        return s.top();
    }
};
