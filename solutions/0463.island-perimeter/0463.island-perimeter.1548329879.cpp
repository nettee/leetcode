class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0;
        int neighbors = 0;
        int H = grid.size();
        int W = grid[0].size();
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (grid[y][x] == 1) {
                    islands++;
                    if (y != 0 && grid[y][x] == grid[y-1][x]) {
                        neighbors++;
                    }
                    if (x != 0 && grid[y][x] == grid[y][x-1]) {
                        neighbors++;
                    }
                }
            }
        }
        return 4 * islands - 2 * neighbors;
    }
};
