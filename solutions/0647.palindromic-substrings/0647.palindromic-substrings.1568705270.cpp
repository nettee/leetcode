class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        int count = 0;
        // odd palindromes
        for (int v = 0; v < N; v++) {
            // odd palindromes, s[v] as pivot
            for (int i = v, j = v; i >= 0 && j < N && s[i] == s[j]; i--, j++) {
                count++;
            }
            // even palindromes, s[v] and s[v+1] as pivot
            for (int i = v, j = v+1; i >= 0 && j < N && s[i] == s[j]; i--, j++) {
                count++;
            }
        }
        return count;
    }
};
