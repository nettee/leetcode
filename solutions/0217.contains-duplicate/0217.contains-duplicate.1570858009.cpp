class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n) > 0) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};
