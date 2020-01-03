class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return false;
        }
        int N = nums.size();
        int i = 0;
        int j = 0;
        // Sliding window: nums[i..j)
        unordered_set<int> seen;
        while (j < N) {
            // max window size: k + 1
            if (i + (k+1) <= j) {
                int x = nums[i++];
                seen.erase(x);
            }
            
            int y = nums[j++];
            if (seen.count(y) > 0) {
                return true;
            }
            seen.insert(y);
        }
        return false;
    }
};
