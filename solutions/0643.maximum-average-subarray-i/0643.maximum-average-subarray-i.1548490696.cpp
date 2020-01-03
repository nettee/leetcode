class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double avg = (double) sum / k;
        double maxavg = avg;
        for (int i = 0; i < N - k; i++) {
            // a[i] --> a[i+k]
            avg += (double) (nums[i+k] - nums[i]) / k;
            maxavg = max(maxavg, avg);
        }
        return maxavg;
    }
};
