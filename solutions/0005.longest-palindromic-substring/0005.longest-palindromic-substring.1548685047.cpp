class Solution {
public:
    string longestPalindrome(string s) {
        string longest;
        for (int k = 0; k < s.length(); k++) {
            string a = find(s, k, k);
            if (a.length() > longest.length()) {
                longest = a;
            }
            if (k > 0) {
                string b = find(s, k-1, k);
                if (b.length() > longest.length()) {
                    longest = b;
                }
            }
        }
        return longest;
    }
    
    string find(string s, int i, int j) {
        if (s[i] != s[j]) {
            return "";
        }
        while (i-1 >= 0 && j+1 < s.length() && s[i-1] == s[j+1]) {
            i--;
            j++;
        }
        return string(s, i, j-i+1);
    }
};
