class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.length();
        int i = 0;
        while (i < N) {
            while (i < N && dominoes[i] != '.') {
                i++;
            }
            int j = i;
            while (j < N && dominoes[j] == '.') {
                j++;
            }
            if (j - i > 0) {
                change_dominoes(dominoes, i, j-1);    
            }
            i = j;
        }
        return dominoes;
    }
    
    void change_dominoes(string& s, int lo, int hi) {
        int N = s.length();
        bool left_push_right = lo-1 >= 0 && s[lo-1] == 'R';
        bool right_push_left = hi+1 < N && s[hi+1] == 'L';
        // Case 1: no fall
        if (!left_push_right && !right_push_left) {
            return;
        
        // Case 2: all fall left
        } else if (!left_push_right && right_push_left) {
            for (int i = lo; i <= hi; i++) {
                s[i] = 'L';
            }
           
        // Case 3: all fall right
        } else if (left_push_right && !right_push_left) {
            for (int i = lo; i <= hi; i++) {
                s[i] = 'R';
            }
         
        // Case 4: fall to middle
        } else {
            for (int i = lo, j = hi; i < j; i++, j--) {
                s[i] = 'R';
                s[j] = 'L';
            }
        }
    }
};
