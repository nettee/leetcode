class Solution {
public:
    int search(vector<int>& nums, int target) {
        int offset = findOffset(nums);
        return find(nums, offset, target);
    }
    
    int findOffset(vector<int>& a) {
        int lo = 0;
        int hi = a.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (a[mid] > a[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
    
    int find(vector<int>& a, int offset, int target) {
        int N = a.size();
        int start = 0;
        int end = N;
        while (start < end) {
            int mid = start + (end - start) / 2;
            int d = a[(mid + offset) % N];
            if (d > target) {
                end = mid;
            } else if (d < target) {
                start = mid + 1;
            } else {
                return (mid + offset) % N;
            }
        }
        return -1;
    }
};
