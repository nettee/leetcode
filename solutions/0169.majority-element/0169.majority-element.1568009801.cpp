class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major;
        int count = 0;
        for (int n : nums) {
            if (count == 0) {
                major = n;
                count++;
            } else {
                if (n == major) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        
        return major;
    }
};
