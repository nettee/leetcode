class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Only 0, 1, 2
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for (int n : nums) {
            if (n == 0) zeros++;
            else if (n == 1) ones++;
            else twos++;
        }
        int k = 0;
        for (int i = 0; i < zeros; i++) {
            nums[k++] = 0;
        }
        for (int i = 0; i < ones; i++) {
            nums[k++] = 1;
        }
        for (int i = 0; i < twos; i++) {
            nums[k++] = 2;
        }
    }
};
