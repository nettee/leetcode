class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) {
            return vector<vector<int>>{{nums[0]}};
        }
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> remaining;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i) {
                    remaining.push_back(nums[j]);
                }
            }
            vector<vector<int>> perms = permute(remaining);
            for (vector<int> perm : perms) {
                perm.push_back(n);
                res.push_back(perm);
            }
        }
        return res;
    }
};
