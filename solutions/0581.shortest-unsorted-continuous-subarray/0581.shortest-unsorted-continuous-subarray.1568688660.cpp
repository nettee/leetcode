class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        
        int i = 0;
        while (i < N && nums[i] == sorted[i]) {
            i++;
        }
        int j = N - 1;
        while (j >= 0 && nums[j] == sorted[j]) {
            j--;
        }
        if (i > j) {
            return 0;
        } else {
            return j - i + 1;
        }
    }
};
