class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Define sum[i, j] = sum(nums[i..j])
        // We need to find all 0 <= i < j < N such that sum[i, j] = k
        // for 0 <= j < N, we count sum[*, j]
        // sum[*, j] = sum[0, j] - sum[0, k], k < j
        unordered_map<int, int> presum;
        presum[0] = 1;
        int sum = 0;
        int res = 0;
        for (int num : nums) {
            sum += num;
            res += presum[sum - k]; // sum - (sum - k) = k
            presum[sum]++;
        }
        return res;
    }
};
