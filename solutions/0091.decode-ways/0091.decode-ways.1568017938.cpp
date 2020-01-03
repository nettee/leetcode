class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        // subproblem:
        // nd(s, k) = number of decodings of s[0..k)
        // nd(s) = nd(s, s.length)
        
        // nd(s, 0) = 1
        // nd(s, 1) = 1
        // nd(s, k) = whether s[k-2] and s[k-1] can decode to 1~26?
        //            true: nd(s, k-2) + nd(s, k-1)
        //            false: nd(s, k-1)
        
        int N = s.length();
        vector<int> dp(N+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int k = 2; k <= N; k++) {
            char c1 = s[k-2];
            char c2 = s[k-1];
            if (c2 >= '1' && c2 <= '9') {
                dp[k] += dp[k-1];
            }
            if (c1 == '1' || (c1 == '2' && c2 >= '0' && c2 <= '6')) {
                dp[k] += dp[k-2];
            }
        }
        return dp[N];
    }
};
