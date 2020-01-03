class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> res;
        backtrack(nums, 0, current, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int k, vector<int>& current, vector<vector<int>>& res) {
        if (k == nums.size()) {
            res.push_back(current);
            return;
        }
        
        for (int i = k; i < nums.size(); i++) {
            swap(nums[k], nums[i]);
            current.push_back(nums[k]);
            backtrack(nums, k+1, current, res);
            current.pop_back();
            swap(nums[k], nums[i]);
        }
    }
};
