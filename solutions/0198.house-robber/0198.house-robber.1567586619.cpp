class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int N = nums.size();
        // subproblem:
        // rob(e) = rob houses [0..e)
        // rob() = rob(N)
        //
        // rob(0) = 0
        // rob(1) = money[0]
        // rob(k) = max:
        // 1. rob house[k-1]
        //    rob(k-2) + money[k-1]
        // 2. do not rob house[k-1]
        //    rob(k-1)
        
        vector<int> dp(N+1, 0);
        
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k = 2; k <= N; k++) {
            dp[k] = max(dp[k-1], dp[k-2] + nums[k-1]);
        }
        
        return dp[N];
    }
};
