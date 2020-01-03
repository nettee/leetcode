class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        vector<string> res;
        backtrack(s, 0, temp, res);
        return res;
    }
    
    // Try to restore s[k..N) for IP address parts
    void backtrack(string& s, int k, vector<string>& temp, vector<string>& res) {
        if (temp.size() == 4) {
            if (k == s.length()) {
                res.push_back(temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3]);
            }
            return;
        }
        
        vector<int> tries;
        for (int i = 1; i <= 3; i++) {
            if (s.length() - k >= i) {
                tries.push_back(i);
            }
        }
        
        for (int t : tries) {
            string p(s, k, t);
            if (p[0] == '0' && p.length() > 1) {
                continue;
            }
            int pn = stoi(p);
            if (pn < 0 || pn > 255) {
                continue;
            }
            temp.push_back(p);
            backtrack(s, k+t, temp, res);
            temp.pop_back();
        }
        
    }
    
};
