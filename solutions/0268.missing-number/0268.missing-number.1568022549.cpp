class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n+1) / 2;
        int actualSum = 0;
        for (int e : nums) {
            actualSum += e;
        }
        return expectedSum - actualSum;
    }
};
