class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(nums.begin(), nums.end());
        backtrack(temp, 0, res);
        return res;
    }
    
    // Permute nums[k..N)
    // Invariant: nums[0..k) are fixed.
    void backtrack(vector<int>& temp, int k, vector<vector<int>>& res) {
        if (k == temp.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = k; i < temp.size(); i++) {
            swap(temp[k], temp[i]);
            backtrack(temp, k+1, res); // Note: k+1, not i+1
            swap(temp[k], temp[i]);
        }
    }
};
