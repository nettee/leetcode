class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (i == N-1 || i == N-2 || nums[i] != nums[i+1] || nums[i] != nums[i+2]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
