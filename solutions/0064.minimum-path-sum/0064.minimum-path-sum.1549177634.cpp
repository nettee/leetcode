class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    paths[i][j] = grid[i][j];
                } else if (i == 0) {
                    paths[i][j] = paths[i][j-1] + grid[i][j];
                } else if (j == 0) {
                    paths[i][j] = paths[i-1][j] + grid[i][j];
                } else {
                    paths[i][j] = min(paths[i][j-1], paths[i-1][j]) + grid[i][j];
                }
            }
        }
        return paths[m-1][n-1];
    }
};
