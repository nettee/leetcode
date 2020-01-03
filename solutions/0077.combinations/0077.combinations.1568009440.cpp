class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> res;
        backtrack(n, k, 1, current, res);
        return res;
    }
    
    void backtrack(int n, int k, int m, vector<int>& current, vector<vector<int>>& res) {
        if (current.size() == k) {
            res.push_back(current);
            return;
        }
        
        for (int i = m; i <= n; i++) {
            current.push_back(i);
            backtrack(n, k, i+1, current, res);
            current.pop_back();
        }
    }
};
