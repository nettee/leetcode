class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> dp(N, 0);
        int maxs = 0;
        // Fill the first line (i = 0)
        for (int j = 0; j < N; j++) {
            dp[j] = matrix[0][j] - '0';
            maxs = max(maxs, dp[j]);
        }
        // Update the line (i > 0)
        for (int i = 1; i < M; i++) {
            int temp; // Store the old upper-left value
            for (int j = 0; j < N; j++) {
                int d = matrix[i][j] - '0';
                if (j == 0) {
                    temp = dp[j];
                    dp[j] = d;
                } else {
                    if (d == 0) {
                        temp = dp[j];
                        dp[j] = 0;
                    } else {
                        int s1 = temp;
                        int s2 = dp[j];
                        int s3 = dp[j-1];
                        temp = dp[j];
                        dp[j] = 1 + min(min(s1, s2), s3);
                    }
                }
                maxs = max(maxs, dp[j]);
            }
        }
        return maxs * maxs;
    }
};
