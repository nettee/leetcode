class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // subproblem:
        // msa(a, k): max subarray ending with a[k]
        // msa(a) = max{ mas(a, k) } for k in [0..N)
        
        // msa(a, 0) = a[0]
        // msa(a, k) = max{ a[k], msa(a, k-1) + a[k] }
        //           = a[k] + max{ 0, msa(a, k-1) }
        
        int N = nums.size();
        vector<int> dp(N, 0);
        
        dp[0] = nums[0];
        int msa = dp[0];
        for (int k = 1; k < N; k++) {
            // calculate msa(a, k)
            dp[k] = nums[k] + max(0, dp[k-1]);
            msa = max(msa, dp[k]);
        }
        
        return msa;
    }
};
