class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        
        int i = 0;
        while (i < N-1 && nums[i] <= nums[i+1]) {
            i++;
        }
        for (int k = i+1; k < N; k++) {
            while (i >= 0 && nums[i] > nums[k]) {
                i--;
            }
            if (i == -1) {
                break;
            }
        }
        
        int j = N-1;
        while (j > 0 && nums[j] >= nums[j-1]) {
            j--;
        }
        for (int k = j-1; k >= 0; k--) {
            while (j < N && nums[j] < nums[k]) {
                j++;
            }
            if (j == N) {
                break;
            }
        }
        
        if (j <= i) {
            return 0;
        } else {
            return (j - i) - 1;
        }
    }
};
