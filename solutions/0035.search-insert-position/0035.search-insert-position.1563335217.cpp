class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 返回第一个 >= target 的元素的位置
        // 实际上就是 lower_bound
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
};
