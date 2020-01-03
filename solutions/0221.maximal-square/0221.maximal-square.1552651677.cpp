class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> pre(N, 0);
        vector<int> cur(N, 0);
        int maxs = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int d = matrix[i][j] - '0';
                if (i == 0 || j == 0 || d == 0) {
                    cur[j] = d;
                } else {
                    int s1 = pre[j-1];
                    int s2 = pre[j];
                    int s3 = cur[j-1];
                    cur[j] = 1 + min(min(s1, s2), s3);
                }
                maxs = max(maxs, cur[j]);
            }
            swap(pre, cur);
        }
        return maxs * maxs;
    }
};
