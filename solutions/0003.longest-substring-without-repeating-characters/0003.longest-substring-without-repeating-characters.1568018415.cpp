class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        
        int N = s.length();
        int longest = 0;
        int i = 0;
        int j = 0;
        while (j < N) {
            while (j < N && seen.find(s[j]) == seen.end()) {
                seen.insert(s[j++]);
            }
            longest = max(longest, j - i);
            if (j == N) {
                break;
            }
            char target = s[j];
            while (i < N && s[i] != s[j]) {
                seen.erase(s[i++]);
            }
            seen.erase(s[i++]);
        }
        return longest;
    }
};
