class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates, temp, 0, target, res);
        return res;
    }
    
    // Use candidates[k..N) to sum up to target
    void backtrack(vector<int>& candidates, vector<int>& temp, int k, int target, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0 && !temp.empty()) {
            res.push_back(temp);
            return;
        }
        for (int i = k; i < candidates.size(); i++) {
            int c = candidates[i];
            temp.push_back(c);
            backtrack(candidates, temp, i, target - c, res);
            temp.pop_back();
        }
    }
};
