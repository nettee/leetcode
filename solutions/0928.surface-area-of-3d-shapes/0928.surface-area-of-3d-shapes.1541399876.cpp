/*
 * [928] Surface Area of 3D Shapes
 *
 * https://leetcode.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (54.67%)
 * Total Accepted:    5.9K
 * Total Submissions: 10.7K
 * Testcase Example:  '[[2]]'
 *
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 * 
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of
 * grid cell (i, j).
 * 
 * Return the total surface area of the resulting shapes.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[2]]
 * Output: 10
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[3,4]]
 * Output: 34
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,0],[0,2]]
 * Output: 16
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int total = 0;
        for (vector<int>& hs : grid) {
            for (int h : hs) {
                if (h > 0) {
                    total += h * 4 + 2;
                }
            }
        }

        int overlap = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 1; y < grid[0].size(); y++) {
                overlap += 2 * min(grid[x][y-1], grid[x][y]);
            }
        }
        for (int y = 0; y < grid[0].size(); y++) {
            for (int x = 1; x < grid.size(); x++) {
                overlap += 2 * min(grid[x-1][y], grid[x][y]);
            }
        }

        return total - overlap;
    }
};

