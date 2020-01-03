class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) {
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (find(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool find(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.length()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (board[i][j] != word[k]) {
            return false;
        }
        
        board[i][j] ^= 128;
        bool found = find(board, word, i-1, j, k+1)
            || find(board, word, i+1, j, k+1)
            || find(board, word, i, j-1, k+1)
            || find(board, word, i, j+1, k+1);
        board[i][j] ^= 128;
        return found;
    }    
};
