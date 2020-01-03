class Solution {
    public boolean isSubsequence(String s, String t) {
        // f(i, j) = s[0..i) is sub? of t[0..j)
        // f(s.length, t.length)
        
        // f(0, *) = true
        // f(*, 0) = false
        // if s[i-1] == t[j-1], f(i, j) = f(i-1, j-1)
        // else,                f(i, j) = f(i, j-1)
        
        int M = s.length();
        int N = t.length();
        boolean[][] dp = new boolean[M+1][N+1];
        for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (i == 0) {
                    dp[i][j] = true;
                } else if (j == 0) {
                    dp[i][j] = false;
                } else {
                    if (s.charAt(i-1) == t.charAt(j-1)) {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[M][N];
    }
}
