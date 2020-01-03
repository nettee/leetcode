class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value -> index
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (seen.find(target - n) != seen.end()) {
                int j = seen[target - n];
                return vector<int>{j, i};
            }
            seen[n] = i;
        }
        return vector<int>{-1, -1};
    }
};
