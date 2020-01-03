class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gn = g.size();
        int sn = s.size();
        // 贪心算法，优先满足那些最容易满足的 children
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int gi = 0;
        int si = 0;
        int count = 0;
        while (gi < gn && si < sn) {
            // Find a good size
            while (si < sn && s[si] < g[gi]) {
                si++;
            }
            if (si >= sn) {
                break;
            }
            // Give s[sj] to g[gi]
            count++;
            si++;
            gi++;
        }
        return count;
    }
};
