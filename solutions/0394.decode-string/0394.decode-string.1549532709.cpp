class Solution {
public:
    string decodeString(string s) {
        int N = s.length();
        deque<string> st;
        int i = 0;
        while (i < N) {
            char c = s[i];
            if (isdigit(c)) {
                int j = i;
                while (j < N && isdigit(s[j])) {
                    j++;
                }
                st.push_back(string(s, i, j-i));
                i = j;
            } else if (isalpha(c)) {
                int j = i;
                while (j < N && isalpha(s[j])) {
                    j++;
                }
                st.push_back(string(s, i, j-i));
                i = j;
            } else if (c == ']') {
                string alpha;
                while (!isdigit(st.back()[0])) {
                    alpha = st.back() + alpha;
                    st.pop_back();
                }
                int t = stoi(st.back());
                st.pop_back();
                string temp;
                while (t-- > 0) {
                    temp += alpha;
                }
                st.push_back(temp);
                i++;
            } else {
                i++;
            }
        }
        string res;
        for (string f : st) {
            res += f;
        }
        return res;
    }
};
