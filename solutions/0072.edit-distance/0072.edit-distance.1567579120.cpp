class Solution {
public:
    int minDistance(string word1, string word2) {
        // Subproblem: 
        // md(w1, e1, w2, e2) = minDistance of word1[0..e1) and word2[0..e2)
        // md(w1, w2) = md(w1, w1.length, w2, w2.length)
        
        // md(w1, e1, w2, e2) = min: md(w1, e1-1, w2, e2) + 1
        //                           md(w1, e1, w2, e2-1) + 1
        //                           md(w1, e1-1, w2, e2-1) + 1 or 0 (w1[e1-1] ==? w2[e2-1])
        // md(w1, 0, w2, 0) = 0
        // md(w1, e1, w2, 0) = e1
        // md(w1, 0, w2, e2) = e2
        
        int N1 = word1.length();
        int N2 = word2.length();
        
        if (N1 == 0) {
            return N2;
        }
        if (N2 == 0) {
            return N1;
        }
        
        vector<int> pre(N2+1, 0);
        vector<int> cur(N2+1, 0);
        // i == 0
        for (int j = 0; j <= N2; j++) {
            pre[j] = j;
        }
        for (int i = 1; i <= N1; i++) {
            for (int j = 0; j <= N2; j++) {
                if (j == 0) {
                    cur[j] = i;
                } else {
                    int v1 = pre[j] + 1;
                    int v2 = cur[j-1] + 1;
                    int v3 = pre[j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
                    cur[j] = min(min(v1, v2), v3);
                }
            }
            swap(pre, cur);
        }
        
        return pre[N2];
    }
};
