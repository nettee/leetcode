class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Remove two distinct number each time, and the remaining number must be the majority
        int maj;
        int count = 0;
        for (int n : nums) {
            if (count == 0) {
                maj = n;
            }
            count += n == maj ? 1 : -1;
        }
        return maj;
    }
};
