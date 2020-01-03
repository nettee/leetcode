class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while (hasNextPerm(nums)) {
            nextPerm(nums);
            res.push_back(nums);
        }            
        return res;
    }
    
    bool hasNextPerm(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                return true;
            }
        }
        return false;
    }
    
    void nextPerm(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int N = nums.size();
        int k = N-1;
        while (k >= 0 && (k == N-1 || nums[k] >= nums[k+1])) {
            k--;
        }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N-1;
        while (nums[j] <= nums[k]) {
            j--;
        }
        swap(nums[j], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};
