class Solution {
public:
    int rob(vector<int>& nums) {
        // Subproblem:
        // rob(a, k): max amount of money after robbing a[0..k)
        // rob(a) = rob(a, a.size)
        //
        // rob(a, k) = max { rob(a, k-1), rob(a, k-2) + a[k-1] }
        // rob(a, 0) = 0
        // rob(a, 1) = a[0]
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        int a = 0;
        int b = nums[0];
        int c;
        for (int k = 2; k <= nums.size(); k++) {
            c = max(a + nums[k-1], b);
            a = b;
            b = c;
        }
        return c;
    }
};
