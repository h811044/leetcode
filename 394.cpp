// 394. Decode String

class Solution {
public:
    string decodeString(string s) {
        stack<tuple<int, string>> st;
        size_t i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                if (i) {
                    string tempString = s.substr(0, i);
                    st.push(make_tuple(0, tempString));
                    s = s.substr(i);
                    i = 0;
                }

                int tempInt = stoi(s, &i);
                st.push(make_tuple(tempInt, ""));
                s = s.substr(i + 1);
                i = 0;
            } else if (s[i] == ']') {
                if (i) {
                    string tempString = s.substr(0, i);
                    st.push(make_tuple(0, tempString));
                    s = s.substr(i);
                    i = 0;
                }

                string composedString = "";
                string popString = get<1>(st.top());
                st.pop();
                while (get<0>(st.top()) == 0) {
                    string tempPopString = get<1>(st.top());
                    st.pop();
                    popString.insert(0, tempPopString);
                }
                int popInt = get<0>(st.top());
                st.pop();
                for (int j = 0; j < popInt; j++) {
                    composedString += popString;
                }
                st.push(make_tuple(0, composedString));
                s = s.substr(i + 1);
                i = 0;
            } else {
                i++;
            }
        }

        while (!st.empty()) {
            string tempPopString = get<1>(st.top());
            st.pop();
            s.insert(0, tempPopString);
        }
        return s;
    }
};
