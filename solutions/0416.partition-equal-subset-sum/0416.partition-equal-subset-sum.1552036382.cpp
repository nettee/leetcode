class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int N = nums.size();
        int S = sum / 2;
        vector<bool> dp(S+1, false);
        dp[0] = true;
        for (int k = 1; k <= N; k++) {
            for (int i = S; i >= nums[k-1]; i--) {
                dp[i] = dp[i] || dp[i-nums[k-1]];
            }
        }
        return dp[S];
    }
};
