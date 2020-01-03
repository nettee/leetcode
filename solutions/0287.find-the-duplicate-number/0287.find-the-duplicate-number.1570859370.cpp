class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int n = nums.size() - 1;
        for (int k = 0; k < n; k++) {
            // swap number (k+1) to nums[k]
            while (nums[k] != k + 1) {
                int j = nums[k] - 1;
                if (nums[k] == nums[j]) {
                    return nums[k];
                }
                swap(nums[k], nums[j]);
            }
        }
        return nums[n];
    }
};
