class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int N = s.length();
        int i = 0;
        int j = 0;
        int longest = 0;
        unordered_set<char> seen;
        while (j < N) {
            while (j < N && seen.find(s[j]) == seen.end()) {
                seen.insert(s[j++]);
                longest = max(longest, j - i);
            }
            if (j >= N) {
                break;
            }
            while (i < j && s[i] != s[j]) {
                seen.erase(s[i++]);
            }
            i++;
            j++;
        }
        return longest;        
    }
};
