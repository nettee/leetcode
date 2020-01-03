class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
    
    // match s[i..) and p[j..)
    bool match(string& s, int i, string& p, int j) {
       
        if (i == s.length() && j == p.length()) {
            return true;
        } else if (i < s.length() && j == p.length()) {
            return false;
        }
        
        if (j+1 < p.length() && p[j+1] == '*') {
            bool thisMatch = i < s.length() && (p[j] == '.' || s[i] == p[j]);
            bool res = match(s, i, p, j+2);
            if (thisMatch) {
                res = res || match(s, i+1, p, j);
            }
            return res;
        } else {
            bool thisMatch = i < s.length() && (p[j] == '.' || s[i] == p[j]);
            return thisMatch && match(s, i+1, p, j+1);
        }
    }
};
