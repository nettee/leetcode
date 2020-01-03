class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // DP idea
        // Subproblem: 
        // ms(a, k) maximum sum of subarrays ends with a[k]
        // ms(a) = max{ms(a, i)}
        //
        // ms(a, 0) = a[0]
        // ms(a, k) = max { ms(a, k-1) + a[k], a[k] }
        //          = max { ms(a, k-1), 0 } + a[k]
        int N = nums.size();
        vector<int> ms(N, 0);
        ms[0] = nums[0];
        for (int k = 1; k < N; k++) {
            ms[k] = max(ms[k-1], 0) + nums[k];
        }
        int maxs = ms[0];
        for (int i = 1; i < N; i++) {
            maxs = max(maxs, ms[i]);
        }
        return maxs;
    }
};
