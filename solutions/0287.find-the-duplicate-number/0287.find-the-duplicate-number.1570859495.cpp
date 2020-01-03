class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return -1;
        }
        int n = nums.size() - 1;
        // If we set nums[k] = k, k = 1, 2, ..., n,
        // then nums[0] is the duplicated number
        for (int i = 0; i < n; i++) {
            int k = nums[0];
            swap(nums[0], nums[k]);
        }
        return nums[0];
    }
};
