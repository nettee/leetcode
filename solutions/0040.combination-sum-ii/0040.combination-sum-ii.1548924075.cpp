class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates, temp, 0, target, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, vector<int>& temp, int k, int target, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0 && !temp.empty()) {
            res.push_back(temp);
            return;
        }
        for (int i = k; i < candidates.size(); i++) {
            if (i > k && candidates[i] == candidates[i-1]) {
                continue;
            }
            int c = candidates[i];
            temp.push_back(c);
            backtrack(candidates, temp, i+1, target - c, res);
            temp.pop_back();
        }
    }
};
