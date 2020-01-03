class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        vector<vector<int>> res;
        backtrack(current, 1, 0, k, n, res);
        return res;
    }
    
    void backtrack(vector<int>& current, int m, int r, int k, int target, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            if (r == k) {
                res.push_back(current);
            }
            return;
        }
        
        if (r == k) {
            return;
        }
        
        for (int i = m; i < 10; i++) {
            current.push_back(i);
            backtrack(current, i+1, r+1, k, target - i, res);
            current.pop_back();
        }
    }
};
