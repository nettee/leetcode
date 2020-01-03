class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(current, 0, res);
        return res;
    }
    
    void backtrack(vector<int>& current, int k, vector<vector<int>>& res) {
        if (k == current.size()) {
            res.push_back(current);
            return;
        }
        
        for (int i = k; i < current.size(); i++) {
            swap(current[k], current[i]);
            backtrack(current, k+1, res);
            swap(current[k], current[i]);
        }
    }
};
