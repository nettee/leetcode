class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0) {
            return res;
        }
        vector<int> current(n, 0);
        for (int i = 0; i < n; i++) {
            current[i] = i + 1;
        }
        
        backtrack(current, 0, k, res);
        return res;
    }
    
    void backtrack(vector<int>& current, int m, int k, vector<vector<int>>& res) {
        if (m == k) {
            vector<int> tmp(current.begin(), current.begin() + k);
            res.push_back(tmp);
        }
        for (int j = m; j < current.size(); j++) {
            if (m == 0 || current[j] >= current[m-1]) {
                swap(current[m], current[j]);
                backtrack(current, m+1, k, res);
                swap(current[m], current[j]);
            }
        }
    }
};
