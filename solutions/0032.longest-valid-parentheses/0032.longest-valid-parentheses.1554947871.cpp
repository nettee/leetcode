class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        for (int k = 0; k < s.length(); k++) {
            int longest = longestValidParentheses(s, k);
            res = max(res, longest);
        }
        return res;
    }
    
    int longestValidParentheses(string& s, int k) {
        int res = 0;
        int depth = 0;
        for (int i = k; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
            }
            if (depth == 0) {
                res = max(res, i - k + 1);
            } else if (depth < 0) {
                break;
            }
        }
        return res;
    }
};
