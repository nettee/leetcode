class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int N = nums.size();
        if (N < 4) {
            return res;
        }
        
        for (int k = 0; k < N; k++) {
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            for (int l = k+1; l < N; l++) {
                if (l > k+1 && nums[l] == nums[l-1]) {
                    continue;
                }
                int i = l+1;
                int j = N-1;
                while (i < j) {
                    int s = nums[k] + nums[l] + nums[i] + nums[j];
                    if (s < target) {
                        i++;
                        while (i < j && nums[i] == nums[i-1]) {
                            i++;
                        }
                    } else if (s > target) {
                        j--;
                        while (i < j && nums[j] == nums[j+1]) {
                            j--;
                        }
                    } else {
                        res.push_back(vector<int>{nums[k], nums[l], nums[i], nums[j]});
                        i++;
                        while (i < j && nums[i] == nums[i-1]) {
                            i++;
                        }
                        j--;
                        while (i < j && nums[j] == nums[j+1]) {
                            j--;
                        }
                    }
                }
            }
        }
        return res;
    }
};
