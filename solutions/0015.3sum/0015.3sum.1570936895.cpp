class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int N = nums.size();
        if (N < 3) {
            return res;
        }
        for (int k = 0; k < N; k++) {
            // first number: nums[k]
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int s = nums[k] + nums[i] + nums[j];
                if (s < 0) {
                    int i2 = i;
                    while (i2 < N && nums[i2] == nums[i]) {
                        i2++;
                    }
                    i = i2;
                } else if (s > 0) {
                    int j2 = j;
                    while (j2 >= 0 && nums[j2] == nums[j]) {
                        j2--;
                    }
                    j = j2;
                } else {
                    res.push_back(vector<int>{nums[k], nums[i], nums[j]});
                    int i2 = i;
                    while (i2 < N && nums[i2] == nums[i]) {
                        i2++;
                    }
                    i = i2;
                    int j2 = j;
                    while (j2 >= 0 && nums[j2] == nums[j]) {
                        j2--;
                    }
                    j = j2;
                }
            }
        }
        return res;
    }
};
