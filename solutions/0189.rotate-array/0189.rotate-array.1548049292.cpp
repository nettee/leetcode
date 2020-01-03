class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Solution 1: ordinary
        int N = nums.size();
        k = k % N;
        if (k == 0) {
            return;
        }
        int* tmp = new int[k];
        for (int i = 0; i < k; i++) {
            tmp[i] = nums[N - k + i];
        }
        for (int i = N - 1; i >= k; i--) {
            nums[i] = nums[i-k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = tmp[i];
        }
    }
};
