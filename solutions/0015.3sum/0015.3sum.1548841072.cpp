class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        set<vector<int>> sol;
        for (int k = 0; k < N; k++) {
            int target = 0 - nums[k];
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int s = nums[i] + nums[j];
                if (s > target) {
                    j--;
                } else if (s < target) {
                    i++;
                } else {
                    sol.insert(vector<int>{nums[i], nums[j], nums[k]});
                    // Important:
                    i++;
                    j--;
                }
            }
        }
        vector<vector<int>> res(sol.begin(), sol.end());
        return res;
    }
};
