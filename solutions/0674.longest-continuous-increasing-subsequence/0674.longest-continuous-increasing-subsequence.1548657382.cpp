class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        int i = 0;
        while (i < N) {
            int j = i;
            while (j < N-1 && nums[j+1] > nums[j]) {
                j++;
            }
            res = max(res, j - i + 1);
            i = j + 1;
        }
        return res;
    }
};
