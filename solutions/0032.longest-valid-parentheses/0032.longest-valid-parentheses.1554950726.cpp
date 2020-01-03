class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        
        stack<pair<int, char>> st; // Stack: (index, char)
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && !st.empty() && st.top().second == '(') {
                st.pop();
            } else {
                st.push(make_pair(i, s[i]));
            }
        }
        
        if (st.empty()) {
            return s.length();
        }
        
        int longest = 0;
        int last = s.length();
        while (!st.empty()) {
            auto e = st.top();
            st.pop();
            int current = e.first;
            longest = max(longest, last - current - 1);
            last = current;
        }
        longest = max(longest, last - (-1) - 1);
        return longest;
    }
};
