class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        }
        // subproblem:
        // lcs(s, t, k, l): longest common subsequence of s[0..k) and t[0..l)
        // lcs(s, t) = lcs(s, t, s.length, t.length)
        
        // lcs(s, t, *, 0) = 0
        // lcs(s, t, 0, *) = 0
        // lcs(s, t, k, l) = max:
        //    1. lcs(s, t, k-1, l)
        //    2. lcs(s, t, k, l-1)
        //    3. lcs(s, t, k-1, l-1) + s[k-1] == t[l-1] ? 1 : 0
        
        int M = text1.length();
        int N = text2.length();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        
        for (int k = 1; k <= M; k++) {
            for (int l = 1; l <= N; l++) {
                int d1 = dp[k-1][l];
                int d2 = dp[k][l-1];
                int d3 = dp[k-1][l-1] + (text1[k-1] == text2[l-1] ? 1 : 0);
                dp[k][l] = max(max(d1, d2), d3);
            }
        }
        return dp[M][N];
    }
};
