class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int k = 0;
        while (k < s.length()) {
            auto p = longestValidParentheses(s, k);
            res = max(res, p.first);
            k = p.second;
        }
        return res;
    }
    
    // return (longest, next)
    pair<int, int> longestValidParentheses(string& s, int k) {
        int longest = 0;
        int next = -1;
        int depth = 0;
        for (int i = k; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
            }
            if (depth == 0) {
                longest = max(longest, i - k + 1);
                if (next == -1) {
                    next = i + 1;
                }
            } else if (depth < 0) {
                break;
            }
        }
        if (next == -1) {
            next = k + 1;
        }
        return make_pair(longest, next);
    }
};
