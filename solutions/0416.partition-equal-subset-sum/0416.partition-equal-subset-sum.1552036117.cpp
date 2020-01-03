class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int N = nums.size();
        int S = sum / 2;
        vector<vector<bool>> dp(N+1, vector<bool>(S+1, false));
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= S; i++) {
                if (i == 0) {
                    dp[k][i] = true;
                } else if (k == 0) {
                    dp[k][i] = false;
                } else {
                    if (i >= nums[k-1]) {
                        dp[k][i] = dp[k-1][i] || dp[k-1][i-nums[k-1]];
                    } else {
                        dp[k][i] = dp[k-1][i];
                    }
                }
            }
        }
        return dp[N][S];
    }
};
