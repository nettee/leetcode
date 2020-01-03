class Solution {
    public int combinationSum4(int[] nums, int target) {
        
        int[] dp = new int[target+1];
        dp[0] = 1;
        
        for (int k = 1; k <= target; k++) {
            int sum = 0;
            for (int n : nums) {
                if (n <= k) {
                    sum += dp[k-n];
                }
            }
            dp[k] = sum;
        }
        
        return dp[target];
    }
}
