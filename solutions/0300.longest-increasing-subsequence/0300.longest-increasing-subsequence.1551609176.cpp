class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // For increasing subsequence with length i+1, the minimal tail element is tails[i]
        // tails must be ascending
        vector<int> tails;
        for (int n : nums) {
            // binary search n in tails
            auto it = lower_bound(tails.begin(), tails.end(), n);
            if (it == tails.end()) {
                // All tails are less than n
                tails.push_back(n);
            } else {
                *it = n;
            }
        }
        return tails.size();
    }
};
