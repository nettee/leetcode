class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int N = A.size();
        for (int i = 0; i < N; i++) {
            reverse(A[i].begin(), A[i].end());
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};
