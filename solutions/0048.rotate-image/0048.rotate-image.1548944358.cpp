class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for (int r = 0; r < N/2; r++) {
            for (int c = r; c < N-1-r; c++) {
                rotate4(matrix, r, c);
            }
        }
    }
    
    void rotate4(vector<vector<int>>& matrix, int i, int j) {
        int N = matrix.size();
        int t = matrix[i][j];
        matrix[i][j] = matrix[N-1-j][i];
        matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
        matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
        matrix[j][N-1-i] = t;
    }
    
};
