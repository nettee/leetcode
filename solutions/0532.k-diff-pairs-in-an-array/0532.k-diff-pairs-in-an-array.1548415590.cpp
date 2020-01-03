class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        if (k == 0) {
            int res = 0;
            for (auto e : counter) {
                if (e.second >= 2) {
                    res++;
                }
            }
            return res;
        } else {
            int res = 0;
            for (auto e : counter) {
                int val = e.first;
                int count = e.second;
                if (counter.find(val + k) != counter.end()) {
                    res++;
                }
            }
            return res;
        }
    }
};
