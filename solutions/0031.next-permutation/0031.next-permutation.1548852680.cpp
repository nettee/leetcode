class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int N = nums.size();
        int k = N-1;
        while (k >= 0 && (k == N-1 || nums[k] >= nums[k+1])) {
            k--;
        }
        if (k < 0) {
            // All descending, return the lowest order
            reverse(nums.begin(), nums.end());
            return;
        }
        // Slightly modification: no need to sort!
        int j = N-1;
        while (nums[j] <= nums[k]) {
            j--;
        }
        swap(nums[k], nums[j]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};
