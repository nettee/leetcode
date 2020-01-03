class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int first = findFirst(nums);
        return find(nums, first, target);
    }
    
    int findFirst(vector<int>& nums) {
        int N = nums.size();
        if (nums[0] < nums[N-1]) {
            return 0;
        }
        int lo = 0;
        int hi = N-1;
        while (nums[lo] > nums[hi]) {
            if (lo + 1 >= hi) {
                return hi;
            }
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[lo]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return -1;
    }
    
    int find(vector<int>& nums, int offset, int target) {
        int N = nums.size();
        int lo = 0;
        int hi = N-1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int v = nums[(offset + mid) % N];
            if (v > target) {
                hi = mid - 1;
            } else if (v < target) {
                lo = mid + 1;
            } else {
                return (mid + offset) % N;
            }
        }
        return -1;
    }
};
