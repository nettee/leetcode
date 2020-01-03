class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> sol;
        int N = nums.size();
        for (int k = 0; k < N; k++) {
            for (int m = k+1; m < N; m++) {
                int kmtarg = target - nums[k] - nums[m];
                int i = m+1;
                int j = N-1;
                while (i < j) {
                    int s = nums[i] + nums[j];
                    if (s > kmtarg) {
                        j--;
                    } else if (s < kmtarg) {
                        i++;
                    } else {
                        sol.insert(vector<int>{nums[k], nums[m], nums[i], nums[j]});
                        i++;
                        j--;
                    }
                }
            }
        }
        vector<vector<int>> res(sol.begin(), sol.end());
        return res;
    }
};
