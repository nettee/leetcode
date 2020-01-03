class Solution {
public:
    string removeOuterParentheses(string S) {
        int N = S.length();
        int depth = 0;
        int last_start = 0;
        string res;
        for (int i = 0; i < N; i++) {
            if (S[i] == '(') {
                depth++;
            } else {
                depth--;
            }
            if (depth == 0) {
                string part = S.substr(last_start + 1, i - last_start - 1);
                res += part;
                last_start = i + 1;
            }
        }
        return res;
    }
};
