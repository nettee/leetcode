class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) {
            return 0;
        } else if (N == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, N-1), rob(nums, 1, N));
    }
    
    int rob(vector<int>& nums, int begin, int end) {
        if (begin >= end) {
            return 0;
        }
        
        vector<int> dp(end + 1, 0);
        
        dp[begin] = 0;
        dp[begin+1] = nums[begin];
        
        for (int k = begin+2; k <= end; k++) {
            dp[k] = max(dp[k-1], dp[k-2] + nums[k-1]);
        }
        
        return dp[end];
    }
};
