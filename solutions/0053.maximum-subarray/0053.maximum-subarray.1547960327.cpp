class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int cursum = 0;
        for (int n : nums) {
            cursum += n;
            maxsum = max(maxsum, cursum);
            cursum = max(cursum, 0);
        }
        return maxsum;
    }
};
