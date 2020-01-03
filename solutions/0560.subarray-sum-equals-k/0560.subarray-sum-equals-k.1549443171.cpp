class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Naive O(n^2) algorithm
        int N = nums.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            // Calculate sum starting from i
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
