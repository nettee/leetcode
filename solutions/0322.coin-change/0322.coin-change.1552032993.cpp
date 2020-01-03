class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int k = 1; k <= amount; k++) {
            for (int c : coins) {
                if (c <= k && dp[k-c] != INT_MAX) {
                    dp[k] = min(dp[k], 1 + dp[k-c]);   
                }
            }
        }
        return dp[amount] < INT_MAX ? dp[amount] : -1;
    }
};
