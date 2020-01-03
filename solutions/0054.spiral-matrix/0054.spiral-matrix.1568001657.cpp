class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        int K = min((m+1)/2, (n+1)/2);
        vector<int> res;
        for (int k = 0; k < K; k++) {
            int rs = k;
            int re = m - 1 - k;
            int cs = k;
            int ce = n - 1 - k;
            // row rs, re, column cs, ce
            if (rs == re) {
                for (int j = cs; j <= ce; j++) {
                    res.push_back(matrix[rs][j]);
                }
            } else if (cs == ce) {
                for (int i = rs; i <= re; i++) {
                    res.push_back(matrix[i][cs]);
                }
            } else {
                for (int j = cs; j < ce; j++) {
                    res.push_back(matrix[rs][j]);
                }
                for (int i = rs; i < re; i++) {
                    res.push_back(matrix[i][ce]);
                }
                for (int j = ce; j > cs; j--) {
                    res.push_back(matrix[re][j]);
                }
                for (int i = re; i > rs; i--) {
                    res.push_back(matrix[i][cs]);
                }
            }
        }
        return res;
    }
};
