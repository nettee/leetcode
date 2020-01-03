class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int N = prices.size() - 1;
        vector<int> diffs(N, 0);
        for (int i = 0; i < N; i++) {
            diffs[i] = prices[i+1] - prices[i];
        }
        
        // subproblem:
        // F(k): max profit of the diffs[0..k) with the last diff
        // G(k) = max{ F(0), F(1), ..., F(k) }
        // maxp() = G(N)
        
        // F(k) = max:
        //        1. G(k-3) + diffs[k-1]
        //        2. F(k-1) + diffs[k-1] (append it!)
        // F(0) = 0
        // F(1) = diffs[0]
        // F(2) = max{ diffs[0] + diffs[1], diffs[1] }
        
        vector<int> f(N+1, 0);
        vector<int> g(N+1, 0);
        f[0] = 0;
        g[0] = f[0];
        for (int k = 1; k <= N; k++) {
            if (k == 1) {
                f[k] = diffs[0];
            } else if (k == 2) {
                f[k] = max(diffs[0], 0) + diffs[1];
            } else {
                f[k] = max(g[k-3], f[k-1]) + diffs[k-1];
            }
            g[k] = max(g[k-1], f[k]);
        }
        
        return g[N];
    }
};
