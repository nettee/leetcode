class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums, target);
        int ub = upperbound(nums, target);
        if (lb == ub) {
            return vector<int>{-1, -1};
        } else {
            return vector<int>{lb, ub-1};
        }
    }
    
    // Find the first element that >= target
    // If not found, return nums.size()
    int lowerbound(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
    
    // Find the first element that > target
    // If not found, return nums.size()
    int upperbound(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] <= target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        return begin;
    }
};
