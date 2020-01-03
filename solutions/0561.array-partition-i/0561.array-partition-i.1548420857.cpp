class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < N; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};
