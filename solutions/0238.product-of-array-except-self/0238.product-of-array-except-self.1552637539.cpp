class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> left_product(N, 0);
        int p = 1;
        for (int i = 0; i < N; i++) {
            left_product[i] = p;
            p *= nums[i];
        }
        vector<int> right_product(N, 0);
        int q = 1;
        for (int i = N-1; i >= 0; i--) {
            right_product[i] = q;
            q *= nums[i];
        }
        vector<int> res;
        for (int i = 0; i < N; i++) {
            res.push_back(left_product[i] * right_product[i]);
        }
        return res;
    }
};
