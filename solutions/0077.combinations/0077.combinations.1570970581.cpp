class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> res;
        backtrack(current, n, k, res);
        return res;
    }
    
    void backtrack(vector<int>& current, int n, int k, vector<vector<int>>& res) {
        if (current.size() == k) {
            res.push_back(current);
            return;
        }
        
        if (n <= 0) {
            return;
        }
        
        backtrack(current, n-1, k, res);
        
        current.push_back(n);
        backtrack(current, n-1, k, res);
        current.pop_back();
    }
};
