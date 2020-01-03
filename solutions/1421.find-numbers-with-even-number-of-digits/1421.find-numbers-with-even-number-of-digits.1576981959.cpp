class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int n : nums) {
            if (digits(n) % 2 == 0) {
                count++;
            }
        }
        return count;
    }
    
    int digits(int num) {
        if (num == 0) {
            return 1;
        }
        
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
};
