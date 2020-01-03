class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int N = nums.size();
        for (int k = 0; k < N; k++) {
            int ktarg = target - nums[k];
            // Two sum closest for a[k+1..N)
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int s = nums[i] + nums[j];
                if (abs(nums[i] + nums[j] + nums[k] - target) < abs(closest - target)) {
                    closest = nums[i] + nums[j] + nums[k];
                }
                if (s > ktarg) {
                    j--;
                } else if (s < ktarg) {
                    i++;
                } else {
                    return target;
                }
            }
        }
        return closest;
    }
};
