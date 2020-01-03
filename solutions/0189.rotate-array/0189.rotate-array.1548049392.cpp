class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Solution 2: O(1) space
        k = k % nums.size();
        if (k == 0) {
            return;
        }
        for (int i = 0; i < k; i++) {
            rotate1(nums);
        }
    }
    
    void rotate1(vector<int>& nums) {
        int N = nums.size();
        int tmp = nums[N-1];
        for (int i = N - 1; i >= 1; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = tmp;
    }
};
