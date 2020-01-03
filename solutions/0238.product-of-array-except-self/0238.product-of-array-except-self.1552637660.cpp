class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 1);
        int left_product = 1;
        for (int i = 0; i < N; i++) {
            res[i] *= left_product;
            left_product *= nums[i];
        }
        int right_product = 1;
        for (int i = N-1; i >= 0; i--) {
            res[i] *= right_product;
            right_product *= nums[i];
        }
        return res;
    }
};
