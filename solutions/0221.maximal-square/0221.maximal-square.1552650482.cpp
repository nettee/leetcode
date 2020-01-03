class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        // dp[i][j] = the largest square size with (i, j) as the bottom-right element
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int maxs = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int d = matrix[i][j] - '0';
                if (i == 0 || j == 0) {
                    dp[i][j] = d;
                } else {
                    if (d == 0) {
                        dp[i][j] = 0;
                    } else {
                        int s1 = dp[i-1][j-1];
                        int s2 = dp[i-1][j];
                        int s3 = dp[i][j-1];
                        dp[i][j] = 1 + min(min(s1, s2), s3);
                    }
                }
                maxs = max(maxs, dp[i][j]);
            }
        }
        return maxs * maxs;
    }
};
