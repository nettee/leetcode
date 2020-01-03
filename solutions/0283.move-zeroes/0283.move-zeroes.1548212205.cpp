class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < N; j++) {
            nums[j] = 0;
        }
    }
};
