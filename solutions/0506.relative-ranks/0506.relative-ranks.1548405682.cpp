class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int N = nums.size();
        vector<int> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        unordered_map<int, int> rank;
        for (int i = 0; i < N; i++) {
            rank[a[i]] = N - i;
        }
        vector<string> res;
        for (int n : nums) {
            int r = rank[n];
            if (r == 1) {
                res.push_back("Gold Medal");
            } else if (r == 2) {
                res.push_back("Silver Medal");
            } else if (r == 3) {
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(r));
            }
        }
        return res;
    }
};
