class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) {
            return 0;
        }
        // subproblem:
        // lcs(A, B, k, l): longest common subarray ending with A[0..k) and B[0..l)
        // lcs(A, B) = max{ lcs(A, B, k, l) }, 0 <= k <= A.length, 0 <= l <= B.length
        
        // lcs(A, B, k, l) = 0 if A[k-1] != B[l-1]
        // lcs(A, B, k, l) = lcs(A, B, k-1, l-1) + 1 if A[k-1] == B[l-1]
        // lcs(A, B, 0, *) = 0
        // lcs(A, B, *, 0) = 0
        
        int M = A.size();
        int N = B.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        int lcs = 0;
        
        for (int k = 1; k <= M; k++) {
            for (int l = 1; l <= N; l++) {
                if (A[k-1] == B[l-1]) {
                    dp[k][l] = dp[k-1][l-1] + 1;
                } else {
                    dp[k][l] = 0;
                }
                lcs = max(lcs, dp[k][l]);
            }
        }

        return lcs;
    }
};
