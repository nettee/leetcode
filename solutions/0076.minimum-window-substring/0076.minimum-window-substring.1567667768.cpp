class Solution {
public:
    string minWindow(string s, string t) {
        int N = s.length();
        
        map<char, int> need;
        for (char c : t) {
            need[c]++;
        }
        int missing = t.length();
        
        map<char, int> meet;
        int i = 0;
        int j = 0;
        int minwind = s.length() + 1;
        string minstr = "";
        while (i < N && j < N) {
            // slide right
            while (j < N && missing > 0) {
                char c = s[j++];
                if (need.find(c) != need.end()) {
                    meet[c]++;
                    if (meet[c] <= need[c]) {
                        missing--;
                    }
                }
            }
            
            // slide left
            while (i < N && missing == 0) {
                if (missing == 0 && j - i < minwind) {
                    minstr = s.substr(i, j - i);
                    minwind = j - i;
                }
                char c = s[i++];
                if (need.find(c) != need.end()) {
                    meet[c]--;
                    if (meet[c] < need[c]) {
                        missing++;
                    }
                }
            }
        }
        
        return minstr;
    }
};
