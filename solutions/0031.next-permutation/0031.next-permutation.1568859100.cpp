class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) {
            return;
        }
        
        int k = N-1;
        while (k >= 0 && (k == N-1 || nums[k] >= nums[k+1])) {
            k--;
        }
        if (k < 0) {
            // all descending
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N-1;
        while (nums[j] <= nums[k]) {
            j--;
        }
        swap(nums[j], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};
