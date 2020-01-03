class Solution {
public:
    int minDistance(string word1, string word2) {
        // Subproblem:
        // med(s, t, j ,k) = min edit distance of s[0..j) and t[0..k)
        // med(s, t) = med(s, t, s.length, t.length)
        //
        // med(s, t, j, k) = ?
        // 1. Delete s[j-1] 
        //    med(s, t, j, k) = med(s, t, j-1, k) + 1
        // 2. Append t[k-1] to s
        //    med(s, t, j, k) = med(s, t, j, k-1) + 1
        // 3. Replace s[j-1] to t[k-1]
        //    med(s, t, j, k) = med(s, t, j-1, k-1) + (s[j-1] == t[k-1] ? 0 : 1)
        //
        // med(s, t, 0, k) = k
        // med(s, t, j, 0) = j
        int N1 = word1.length();
        int N2 = word2.length();
        if (N1 == 0 || N2 == 0) {
            return N1 + N2;
        }
        
        vector<int> pre(N2+1, 0);
        vector<int> cur(N2+1, 0);
        for (int j = 0; j <= N1; j++) {
            for (int k = 0; k <= N2; k++) {
                if (j == 0) {
                    pre[k] = k;
                } else if (k == 0) {
                    cur[k] = j;
                } else {
                    int d1 = pre[k] + 1;
                    int d2 = cur[k-1] + 1;
                    int d3 = pre[k-1] + (word1[j-1] == word2[k-1] ? 0 : 1);
                    cur[k] = min(min(d1, d2), d3);
                }
            }
            if (j != 0) {
                swap(pre, cur);
            }
        }
        return pre[N2];
    }
};
