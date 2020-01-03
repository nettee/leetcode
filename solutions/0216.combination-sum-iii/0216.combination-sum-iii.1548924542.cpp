class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(k, temp, 1, n, res);
        return res;
    }
    
    // [1..m) are already used, use [m..9]
    void backtrack(int k, vector<int>& temp, int m, int target, vector<vector<int>>& res) {
        if (target < 0) {
            return;
        }
        if (target == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (target == 0 && temp.size() != k) {
            return;
        }
        for (int i = m; i <= 9; i++) {
            temp.push_back(i);
            backtrack(k, temp, i+1, target - i, res);
            temp.pop_back();
        }
    }
};
