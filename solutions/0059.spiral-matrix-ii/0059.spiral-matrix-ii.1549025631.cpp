class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<int>(n, 0));
        }
        int R = (n+1)/2; // number of rolls;
        int c = 0;
        for (int k = 0; k < R; k++) {
            if (k == n-1-k) {
                res[k][k] = ++c;
            } else {
                for (int j = k; j < n-1-k; j++) {
                    res[k][j] = ++c;
                }
                for (int i = k; i < n-1-k; i++) {
                    res[i][n-1-k] = ++c;
                }
                for (int j = n-1-k; j > k; j--) {
                    res[n-1-k][j] = ++c;
                }
                for (int i = n-1-k; i > k; i--) {
                    res[i][k] = ++c;
                }
            }
        }
        return res;
    }
};
