class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // subproblem:
        // lis(a, k): longest inc subseq ending with a[k]
        // lis(a) = max{ lis(a, k) }, 0 <= k < N
        
        // lis(a, 0) = 1
        // lis(a, k) = max{ lis(a, i) + 1 } where a[k] > a[i], 0 <= i < k
        
        int N = nums.size();
        vector<int> dp(N, 0);
        
        dp[0] = 1;
        int longest = dp[0];
        for (int k = 1; k < N; k++) {
            dp[k] = 1;
            for (int i = 0; i < k; i++) {
                if (nums[k] > nums[i]) {
                    dp[k] = max(dp[k], dp[i] + 1);
                }
            }
            longest = max(longest, dp[k]);
        }
        
        return longest;
    }
};
