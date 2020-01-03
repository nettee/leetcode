class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        unordered_map<string, int> occur;
        
        for (int size = minSize; size <= maxSize; size++) {
            countOccur(s, maxLetters, size, occur);
        }
        
        int mo = 0;
        for (auto e : occur) {
            mo = max(mo, e.second);
        }
        return mo;
    }
    
    void countOccur(string& s, int maxLetters, int size, unordered_map<string, int>& occur) {
        if (s.length() < size) {
            return;
        }
        
        unordered_map<char,int> m;
        int letters = 0;
        for (int k = 0; k < size; k++) {
            char c = s[k];
            m[c]++;
            if (m[c] == 1) {
                letters++;
            }
        }
        if (letters <= maxLetters) {
            string t = s.substr(0, size);
            occur[t]++;
        }
        
        int i = 0;
        int j = size;
        while (j < s.length()) {
            char c1 = s[i++];
            m[c1]--;
            if (m[c1] == 0) {
                letters--;
            }
            char c2 = s[j++];
            m[c2]++;
            if (m[c2] == 1) {
                letters++;
            }
            if (letters <= maxLetters) {
                string t = s.substr(i, j-i);
                occur[t]++;
            }
        }
    }
};
