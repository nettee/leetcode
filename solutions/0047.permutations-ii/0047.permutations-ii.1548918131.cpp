class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // No need to sort
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
        unordered_set<int> appeared;
        for (int i = k; i < temp.size(); i++) {
            if (appeared.find(temp[i]) != appeared.end()) {
                continue;
            }
            appeared.insert(temp[i]);
            swap(temp[k], temp[i]);
            backtrack(temp, k+1, res); // Note: k+1, not i+1
            swap(temp[k], temp[i]);
        }
    }
};
