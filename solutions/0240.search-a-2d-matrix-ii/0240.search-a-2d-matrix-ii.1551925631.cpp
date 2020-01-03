class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        int i = 0; // i increases from 0 to M - 1
        int j = N - 1; // j decreases from N - 1 to 0
        while (i < M && j >= 0) {
            int d = matrix[i][j];
            if (target < d) {
                j--;
            } else if (target > d) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
    
};
