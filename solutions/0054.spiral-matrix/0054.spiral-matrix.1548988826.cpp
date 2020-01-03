class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        int M = matrix.size();
        int N = matrix[0].size();
        int R = min((M+1)/2, (N+1)/2); // number of rolls
        vector<int> res;
        for (int k = 0; k < R; k++) {
            // The k-th roll:
            // r = k, r = M-1-k
            // c = k, c = N-1-k
            if (k == M-1-k) {
                // Only one row
                for (int j = k; j <= N-1-k; j++) {
                    res.push_back(matrix[k][j]);
                }
            } else if (k == N-1-k) {
                // Only one column
                for (int i = k; i <= M-1-k; i++) {
                    res.push_back(matrix[i][k]);
                }
            } else {
                for (int j = k; j < N-1-k; j++) {
                    res.push_back(matrix[k][j]);
                }
                for (int i = k; i < M-1-k; i++) {
                    res.push_back(matrix[i][N-1-k]);
                }
                for (int j = N-1-k; j > k; j--) {
                    res.push_back(matrix[M-1-k][j]);
                }
                for (int i = M-1-k; i > k; i--) {
                    res.push_back(matrix[i][k]);
                }
            }
        }
        return res;
    }
};
