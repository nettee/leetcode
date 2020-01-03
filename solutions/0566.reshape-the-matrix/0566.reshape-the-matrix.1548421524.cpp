class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() * nums[0].size() != r * c) {
            return nums;
        }
        vector<vector<int>> res;
        for (int i = 0; i < r; i++) {
            res.push_back(vector<int>());
            for (int j = 0; j < c; j++) {
                res[i].push_back(get(nums, i * c + j));
            }
        }
        return res;
    }
    
    int get(vector<vector<int>>& matrix, int n) {
        int M = matrix[0].size();
        return matrix[n/M][n%M];
    }
};
