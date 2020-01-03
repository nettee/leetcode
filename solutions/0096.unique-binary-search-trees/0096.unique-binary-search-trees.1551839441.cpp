class Solution {
public:
    int numTrees(int n) {
        // Subproblem:
        // ubst(k): unique BST's for k numbers
        // 
        // ubst(k) = sum (1<=i<=k) { ubst(i-1) * ubst(k-i) }
        // ubst(0) = 1
        if (n == 0) {
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= k; i++) {
                dp[k] += dp[i-1] * dp[k-i];
            }
        }
        return dp[n];
    }
};
