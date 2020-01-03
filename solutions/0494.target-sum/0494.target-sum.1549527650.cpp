class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int K = accumulate(nums.begin(), nums.end(), 0);
        if (K < S) {
            return 0;
        }
        if ((K + S) % 2 != 0) {
            return 0;
        }
        int T = (K + S) / 2;
        vector<int> dp(T+1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int k = T; k >= n; k--) {
                dp[k] += dp[k-n];
            }
        }
        return dp[T];
    }
};
