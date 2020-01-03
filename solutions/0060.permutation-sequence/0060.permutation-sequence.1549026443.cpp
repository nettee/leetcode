class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        string init;
        for (int i = 1; i <= n; i++) {
            init += '0' + i;
        }
        for (int i = 0; i < k-1; i++) {
            next_perm(init);
        }
        return init;
    }
    
    void next_perm(string& s) {
        int N = s.length();
        // Find the right-most j such that s[j] < s[j+1]
        int j = N-2;
        while (j > 0 && s[j] > s[j+1]) {
            j--;
        }
        if (j < 0) {
            // All elements are descending
            reverse(s.begin(), s.end());
            return;
        }
        // Find the right-most k such that s[k] > s[j]
        // Note that k > j, and all elements between s[j] and s[k] are larger than s[k]
        int k = N-1;
        while (k > 0 && s[k] < s[j]) {
            k--;
        }
        swap(s[j], s[k]);
        // s[j+1..N) must be in descending order, sort them to ascending
        reverse(s.begin() + j + 1, s.end());
    }
};
