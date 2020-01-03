class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if (i > k && candidates[i] == candidates[i-1]) {
                continue;
            }
            current.push_back(candidates[i]);
            backtrack(candidates, i+1, current, target - candidates[i], res);
            current.pop_back();
        }
    }
};
