class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        // presum[i] = sum of nums[0..i)
        vector<int> presum(N+1, 0);
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            presum[i+1] = sum;
        }
        
        // sum of nums[i..j) = sum of nums[0..j) - sum of nums[0..i)
        int count = 0;
        for (int i = 0; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                if (presum[j] - presum[i] == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
