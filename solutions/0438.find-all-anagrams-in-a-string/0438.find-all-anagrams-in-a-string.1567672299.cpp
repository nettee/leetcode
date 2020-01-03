class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int N = s.length();
        int n = p.length();
        if (N < n) {
            return vector<int>();
        }
        
        map<char, int> need;
        for (char c : p) {
            need[c]++;
        }
        
        vector<int> res;
        
        int missing = n;
        map<char, int> seen;
        for (int k = 0; k < n; k++) {
            char c = s[k];
            if (need.find(c) != need.end()) {
                seen[c]++;
                if (seen[c] <= need[c]) {
                    missing--;
                }
            }
        }
        if (missing == 0) {
            res.push_back(0);
        }
        
        // Fixed-length sliding window
        int i = 0;
        int j = n;
        while (j < N) {
            // slide right
            char in = s[j++];
            if (need.find(in) != need.end()) {
                seen[in]++;
                if (seen[in] <= need[in]) {
                    missing--;
                }
            }
            
            char out = s[i++];
            if (need.find(out) != need.end()) {
                seen[out]--;
                if (seen[out] < need[out]) {
                    missing++;
                }
            }
            
            if (missing == 0) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
