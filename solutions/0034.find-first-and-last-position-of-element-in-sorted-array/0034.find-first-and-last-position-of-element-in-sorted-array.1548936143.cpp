class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int k = search(nums, target);
        if (k == -1) {
            return vector<int>{-1, -1};
        }
        int i = k;
        while (i >= 0 && nums[i] == nums[k]) {
            i--;
        }
        int j = k;
        while (j < nums.size() && nums[j] == nums[k]) {
            j++;
        }
        return vector<int>{i+1, j-1};
    }
    
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
