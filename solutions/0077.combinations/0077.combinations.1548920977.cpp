class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(n, k, temp, 1, res);
        return res;
    }
    
    // [1..m) are already used, use m <= i <= n
    void backtrack(int n, int k, vector<int>& temp, int m, vector<vector<int>>& res) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (m > n) {
            return;
        }
        for (int i = m; i <= n; i++) {
            temp.push_back(i);
            backtrack(n, k, temp, i+1, res);
            temp.pop_back();
        }
    }
};
