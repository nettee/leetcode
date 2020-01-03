class Solution {
    public int numTrees(int n) {
        if (n <= 0) {
            return 0;
        }
        
        // f(0) = 1
        // f(1) = 1
        // f(2) = f(0)f(1) + f(1)f(0)
        // f(k) = sum{ f(i-1)f(k-i) } 1 <= i <= k
        
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for (int k = 2; k <= n; k++) {
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                sum += dp[i-1] * dp[k-i];
            }
            dp[k] = sum;
        }
        
        return dp[n];
    }
}
