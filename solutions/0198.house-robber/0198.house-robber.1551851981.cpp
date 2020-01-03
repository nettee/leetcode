class Solution {
public:
    int rob(vector<int>& nums) {
        // Subproblem:
        // rob(a, k): max amount of money after robbing a[0..k)
        // rob(a) = rob(a, a.size)
        //
        // rob(a, k) = max { rob(a, k-1), rob(a, k-2) + a[k-1] }
        // rob(a, 0) = 0
        // rob(a, 1) = a[0]
        if (nums.empty()) {
            return 0;
        }
        int N = nums.size();
        vector<int> dp(N+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k = 2; k <= N; k++) {
            dp[k] = max(dp[k-1], dp[k-2] + nums[k-1]);
        }
        return dp[N];
    }
};
