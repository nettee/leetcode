class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(candidates, 0, current, target, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int k, vector<int>& current, int target, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(current);
            return;
        }
        for (int i = k; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, i, current, target - candidates[i], res);
            current.pop_back();
        }
    }
};
