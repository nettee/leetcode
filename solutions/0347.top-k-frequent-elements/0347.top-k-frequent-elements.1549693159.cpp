class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        vector<pair<int, int>> v(counter.begin(), counter.end());
        sort(v.begin(), v.end(), [] 
                (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        });
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};
