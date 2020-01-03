class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int N = s.length();
        
        unordered_set<char> seen;
        
        int longest = 0;
        int i = 0;
        int j = 0;
        while (j < N) {
            // slide right
            while (j < N && seen.find(s[j]) == seen.end()) {
                seen.insert(s[j++]);
            }
            
            longest = max(longest, j - i);
            
            if (j == N) {
                break;
            }
            
            // slide left
            char toRemove = s[j];
            while (i < N && s[i] != toRemove) {
                seen.erase(s[i++]);
            }
            seen.erase(s[i++]);
        }
        
        return longest;
    }
};
