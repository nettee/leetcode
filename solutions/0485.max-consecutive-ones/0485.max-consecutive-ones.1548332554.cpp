class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int i = 0;
        int N = nums.size();
        while (i < N) {
            while (i < N && nums[i] != 1) {
                i++;
            }
            int j = i;
            while (j < N && nums[j] == 1) {
                j++;
            }
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};
