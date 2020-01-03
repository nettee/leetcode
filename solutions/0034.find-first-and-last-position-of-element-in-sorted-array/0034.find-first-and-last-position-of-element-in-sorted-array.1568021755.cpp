class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        if (lb == ub) {
            return vector<int>{-1, -1};
        } else {
            return vector<int>{lb - nums.begin(), ub - nums.begin() - 1};
        }
    }
};
