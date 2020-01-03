class Solution {
public:
    int minDistance(string word1, string word2) {
        // Subproblem:
        // med(s, t, j ,k) = min edit distance of s[0..j) and t[0..k)
        // med(s, t) = med(s, t, s.length, t.length)
        //
        // med(s, t, j, k) = ?
        // 1. Delete s[j-1] 
        //    med(s, t, j, k) = med(s, t, j-1, k) + 1
        // 2. Append t[k-1] to s
        //    med(s, t, j, k) = med(s, t, j, k-1) + 1
        // 3. Replace s[j-1] to t[k-1]
        //    med(s, t, j, k) = med(s, t, j-1, k-1) + (s[j-1] == t[k-1] ? 0 : 1)
        //
        // med(s, t, 0, k) = k
        // med(s, t, j, 0) = j
        int N1 = word1.length();
        int N2 = word2.length();
        if (N1 == 0 || N2 == 0) {
            return N1 + N2;
        }
        
        vector<int> dp(N2+1, 0);
        // j == 0 case
        for (int k = 0; k <= N2; k++) {
            dp[k] = k;
        }
        for (int j = 1; j <= N1; j++) {
            // k == 0 case
            int ul = dp[0]; // upper-left value
            dp[0] = j;
            for (int k = 1; k <= N2; k++) {
                // Calculate dp[k]
                int l = dp[k-1];
                int u = dp[k];
                int d1 = l + 1;
                int d2 = u + 1;
                int d3 = ul + (word1[j-1] == word2[k-1] ? 0 : 1);
                ul = dp[k];
                dp[k] = min(min(d1, d2), d3);
            }
        }
        return dp[N2];
    }
};
