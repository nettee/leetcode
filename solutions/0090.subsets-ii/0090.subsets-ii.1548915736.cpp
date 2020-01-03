class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(nums, temp, 0, res);
        return res;
    }
    
    // Invariant: nums[0..k) are used.
    void backtrack(vector<int>& nums, vector<int>& temp, int k, vector<vector<int>>& res) {
        res.push_back(temp);
        if (k >= nums.size()) {
            return;
        }
        for (int i = k; i < nums.size(); i++) {
            if (i > k && nums[i] == nums[i-1]) {
                continue;
            }
            int n = nums[i];
            temp.push_back(n);
            backtrack(nums, temp, i+1, res);
            temp.pop_back();
        }
    }
};
