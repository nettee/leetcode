class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        // DP subproblem:
        // ls(s, k) = longest substring ending with s[k]
        // ls(s) = ls(s, N-1)
        //
        // If s[k] is not appeared in s[0..k):
        //     ls(s, k) = ls(s, k-1) + 1
        // Else: Let i = last appeared index of s[k]
        //     ls(s, k) = min{ ls(s, k-1) + 1, k - i}
        //
        // ls(s, 0) = 1
        
        int N = s.length();
        unordered_map<char,int> last_index;
        vector<int> dp(N, 0);
        
        int res = 0;
        
        for (int k = 0; k < N; k++) {
            // Calculate dp[k] = ls(s, k)
            char c = s[k];
            if (k == 0) {
                dp[k] = 1;
            } else {
                if (last_index.find(c) == last_index.end()) {
                    dp[k] = dp[k-1] + 1;
                } else {
                    int i = last_index[c];
                    dp[k] = min(dp[k-1] + 1, k - i);
                }
            }
            res = max(res, dp[k]);
            last_index[c] = k;
        }
        
        return res;
    }
};
