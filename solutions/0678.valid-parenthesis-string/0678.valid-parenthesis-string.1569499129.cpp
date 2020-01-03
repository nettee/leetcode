class Solution {
public:
    bool checkValidString(string s) {
        bool valid = false;
        backtrack(s, 0, 0, valid);
        return valid;
    }
    
    void backtrack(string& s, int k, int depth, bool& valid) {
        if (valid) {
            return;
        }
        if (k == s.length()) {
            if (depth == 0) {
                valid = true;
            }
            return;
        }
        char c = s[k];
        if (c == '(' || c == '*') {
            backtrack(s, k+1, depth+1, valid);
        }
        if (c == ')' || c == '*') {
            if (depth > 0) {
                backtrack(s, k+1, depth-1, valid);
            }
        } 
        if (c == '*') {
            backtrack(s, k+1, depth, valid);
        }
    }
};
