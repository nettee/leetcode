class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();
        int i = 0;
        int j = 0;
        while (i < N) {
            while (i < N && nums[i] == 0) {
                i++;
            }
            if (i < N) {
                nums[j++] = nums[i++];
            }
        }
        while (j < N) {
            nums[j] = 0;
            j++;
        }
    }
};
