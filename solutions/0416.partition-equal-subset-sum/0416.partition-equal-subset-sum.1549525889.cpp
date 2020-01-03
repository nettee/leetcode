class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int K = accumulate(nums.begin(), nums.end(), 0);
        if (K % 2 != 0) {
            return false;
        }
        int N = nums.size();
        // Subproblem: 
        // P(j, k): there is a subset of nums[0..j) sums to k
        // canPartition(nums) = P(K/2, N)
        //
        // P(j, k) = P(j-1, k) || P(j-1, k - nums[j])
        // P(0, 0) = true
        // P(0, *) = false
        vector<bool> dp(K/2+1, false);
        dp[0] = true;
        for (int j = 1; j <= N; j++) {
            int n = nums[j-1];
            for (int k = K/2; k >= n; k--) {
                dp[k] = dp[k] || dp[k - n];
            }
        }
        return dp[K/2];
    }
    
};
