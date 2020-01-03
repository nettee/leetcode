class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        string T = preprocess(s);
        int N = T.length();
        int* P = new int[N];
        int C = 0;
        int R = 0;
        for (int i = 1; i < N-1; i++) {
            int mirror = 2 * C - i;
            if (i < R) {
                P[i] = min(R-i, P[mirror]);
            } else {
                P[i] = 0;
            }
            while (T[i-1-P[i]] == T[i+1+P[i]]) {
                P[i]++;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        int maxlen = 0;
        int c = 0;
        for (int i = 1; i < N-1; i++) {
            if (P[i] > maxlen) {
                c = i;
                maxlen = P[i];
            }
        }
        delete[] P;
        return string(s, (c-1-maxlen)/2, maxlen);
    }
    
    string preprocess(string s) {
        string res = "^";
        for (char c : s) {
            res += '#';
            res += c;
        }
        res += "#$";
        return res;
    }
};
