class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if (s.size() < 3) {
            auto it = s.rbegin();
            return *it;
        } else {
            auto it = s.rbegin();
            ++it;
            ++it;
            return *it;
        }
    }
};
