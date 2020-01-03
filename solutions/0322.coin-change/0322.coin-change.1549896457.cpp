class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            // Calculate dp[i]
            int fewest = INT_MAX;
            for (int coin : coins) {
                if (i >= coin && dp[i-coin] != -1) {
                    fewest = min(fewest, dp[i-coin]);
                }
            }
            dp[i] = (fewest == INT_MAX) ? -1 : 1 + fewest;
        }
        return dp[amount];
    }
};
