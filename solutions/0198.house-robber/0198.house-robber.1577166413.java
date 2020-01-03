class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        // subproblem:
        // rob(k) = rob nums[0..k)
        
        // rob(0) = 0
        // rob(1) = nums[0]
        // rob(k) = max{ rob(k-1), rob(k-2) + nums[k-1] }
        
        int N = nums.length;
        int[] dp = new int[N+1];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k = 2; k <= N; k++) {
            dp[k] = Math.max(dp[k-1], dp[k-2] + nums[k-1]);
        }
        return dp[N];
    }
}
