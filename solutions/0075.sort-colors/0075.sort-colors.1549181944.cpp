class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Three-way partition in quicksort
        int lt = 0;
        int i = 0;
        int gt = nums.size();
        // Invariant:
        // nums[begin..lt) are elements that < 1
        // nums[lt..i) are elements that = 1
        // nums[gt..end) are elements that > 1
        while (i < gt) {
            if (nums[i] < 1) {
                swap(nums[lt++], nums[i++]);
            } else if (nums[i] > 1) {
                swap(nums[i], nums[--gt]);
            } else {
                i++;
            }
        }
    }
};
