class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int N = points.size();
        
        int res = 0;
        for (int i = 0; i < N; i++) {
            unordered_map<long, int> counter;
            for (int j = 0; j < N; j++) {
                counter[dist(points[i], points[j])]++;
            }
            for (auto e : counter) {
                int c = e.second;
                if (c > 1) {
                    res += c * (c - 1);
                }
            }
        }
        return res;
    }
    
    long dist(pair<int, int>& p, pair<int, int>& q) {
        return ((long) (p.first - q.first)) * (p.first - q.first) 
            + ((long) (p.second - q.second)) * (p.second - q.second);
    }
};
