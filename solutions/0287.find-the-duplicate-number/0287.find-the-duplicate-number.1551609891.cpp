class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // For each round, let e0 = a[0], swap a[0] and a[e0]
        // After n rounds, a[0] is the duplicated element.
        int n = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            int e0 = nums[0];
            if (nums[0] == nums[e0]) {
                return nums[0];
            } else {
                swap(nums[0], nums[e0]);
            }
        }
        return nums[0];
    }
};
