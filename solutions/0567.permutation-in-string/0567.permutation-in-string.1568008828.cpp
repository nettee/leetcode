class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }
        vector<int> need(26, 0);
        int missing = 0;
        for (char c : s1) {
            need[c-'a']++;
            missing++;
        }
        
        vector<int> seen(26, 0);
        
        int n = s1.length();
        int N = s2.length();
        
        for (int i = 0; i < n; i++) {
            int idx = s2[i]-'a';
            seen[idx]++;
            if (seen[idx] <= need[idx]) {
                missing--;
            }
        }
        if (missing == 0) {
            return true;
        }
        
        for (int i = n; i < N; i++) {
            int idx1 = s2[i-n]-'a';
            seen[idx1]--;
            if (seen[idx1] < need[idx1]) {
                missing++;
            }
            
            int idx2 = s2[i]-'a';
            seen[idx2]++;
            if (seen[idx2] <= need[idx2]) {
                missing--;
            }
            
            if (missing == 0) {
                return true;
            }
        }
        
        return false;
        
        
        
    }
};
