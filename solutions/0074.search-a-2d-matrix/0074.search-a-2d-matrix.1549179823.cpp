class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int N = m * n;
        int lo = 0;
        int hi = N;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int d = matrix[mid/n][mid%n];
            if (d < target) {
                lo = mid + 1;
            } else if (d > target) {
                hi = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};
