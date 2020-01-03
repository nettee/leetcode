class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Another solution. O(n) time and O(1) space
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            int n = abs(nums[i]);
            // Negative it to mark appearing
            if (nums[n-1] > 0) {
                nums[n-1] = -nums[n-1];
            }
        }
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
