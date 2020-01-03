class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        int res = 0;
        for (auto e : counter) {
            int val = e.first;
            int count = e.second;
            if (counter.find(val+1) != counter.end()) {
                res = max(res, count + counter[val+1]);
            }
        }
        return res;
    }
};
