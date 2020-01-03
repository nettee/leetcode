class Solution {
public:
    int rob(vector<int>& nums) {
        // Case 1: rob the first house (so you cannot rob the last)
        // rob(a) = rob(a, a.size-1)
        // rob(a, 0) = 0
        // rob(a, 1) = a[0]
        // rob(a, k) = max{ rob(a, k-2) + a[k-1], rob(a, k-1) }
        //
        // Case 2: do not rob the first house (so you can rob the last)
        // rob(a) = rob(a, a.size)
        // rob(a, 0) = 0
        // rob(a, 1) = 0
        // rob(a, k) = max{ rob(a, k-2) + a[k-1], rob(a, k-1) }
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        // Case 1
        int a = 0;
        int b = nums[0];
        int c;
        for (int k = 2; k <= nums.size() - 1; k++) {
            c = max(a + nums[k-1], b);
            a = b;
            b = c;
        }
        // Case 2
        int d = 0;
        int e = 0;
        int f;
        for (int k = 2; k <= nums.size(); k++) {
            f = max(d + nums[k-1], e);
            d = e;
            e = f;
        }
        return max(c, f);
    }
};
