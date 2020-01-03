class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int N = points.size();
        
        int res = 0;
        for (int i = 0; i < N; i++) {
            vector<long> dists;
            for (int j = 0; j < N; j++) {
                dists.push_back(dist(points[i], points[j]));
            }
            res += count(dists);
        }
        return res;
    }
    
    int count(vector<long>& dists) {
        sort(dists.begin(), dists.end());
        
        int res = 0;
        
        int i = 0;
        while (i < dists.size()) {
            int j = i;
            while (j < dists.size() && dists[j] == dists[i]) {
                j++;
            }
            int n = j - i;
            res += n * (n - 1);
            i = j;
        }
        
        return res;
    }
    
    long dist(pair<int, int>& p, pair<int, int>& q) {
        return ((long) (p.first - q.first)) * (p.first - q.first) 
            + ((long) (p.second - q.second)) * (p.second - q.second);
    }
};
