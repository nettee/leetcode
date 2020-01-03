class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // We should give cookies to children that is less greedy.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0;
        int sj = 0;
        int res = 0;
        while (gi < g.size()) {
            while (sj < s.size() && s[sj] < g[gi]) {
                sj++;
            }
            if (sj < s.size()) {
                // We can assign cookie[j] to child[i];
                res++;
                gi++;
                sj++;
            } else {
                break;
            }
        }
        return res;
    }
};
