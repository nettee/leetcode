class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int cursum = 0;
        for (int n : nums) {
            cursum += n;
            // The order of the below two statements is important
            // Corner case: what if all elements are negative?
            maxsum = max(maxsum, cursum);
            cursum = max(cursum, 0);
        }
        return maxsum;
    }
};
