/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (38.35%)
 * Total Accepted:    162.7K
 * Total Submissions: 424.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return valid_rows(board) && valid_cols(board) && valid_boxes(board);
    }
private:
    bool valid_rows(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<char>& row = board[i];
            if (has_rep(row)) {
                return false;
            }
        }
        return true;
    }

    bool valid_cols(vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            vector<char> col;
            for (int i = 0; i < 9; i++) {
                col.push_back(board[i][j]);
            }
            if (has_rep(col)) {
                return false;
            }
        }
        return true;
    }

    bool valid_boxes(vector<vector<char>>& board) {
        for (int b = 0; b < 9; b++) {
            int R = b / 3;
            int C = b % 3;
            vector<char> box;
            for (int i = R * 3; i < (R+1) * 3; i++) {
                for (int j = C * 3; j < (C+1) * 3; j++) {
                    box.push_back(board[i][j]);
                }
            }
            if (has_rep(box)) {
                return false;
            }
        }
        return true;
    }

    bool has_rep(vector<char>& unit) {
        bool seen[9];
        for (int i = 0; i < 9; i++) {
            seen[i] = false;
        }
        for (int i = 0; i < 9; i++) {
            char c = unit[i];
            if (c == '.') {
                continue;
            }
            int d = c - '1';
            if (seen[d]) {
                return true;
            }
            seen[d] = true;
        }
        return false;
    }
};

