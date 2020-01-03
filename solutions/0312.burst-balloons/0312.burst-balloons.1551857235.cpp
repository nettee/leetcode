class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return mc(nums, 0, N, dp);
    }
    
    // Max coins in a[start..end)
    int mc(vector<int>& a, int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        } else {
            int max_coin = INT_MIN;
            for (int k = start; k < end; k++) {
                // We burst a[k] LAST
                int last_coin = get(a, start-1) * a[k] * get(a, end);
                int mc_left = mc(a, start, k, dp);
                int mc_right = mc(a, k+1, end, dp);
                max_coin = max(max_coin, mc_left + mc_right + last_coin);
            }
            dp[start][end] = max_coin;
            return max_coin;
        }
    }
    
    int get(vector<int>& a, int i) {
        if (i == -1 || i == a.size()) {
            return 1;
        } else {
            return a[i];
        }
    }
};
