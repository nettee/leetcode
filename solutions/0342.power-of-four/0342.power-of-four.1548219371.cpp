class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }
        while (num > 0) {
            if (num == 1) {
                return true;
            } 
            if ((num & 0x3) != 0) {
                return false;
            }
            num >>= 2;
        }
        return false;
    }
};
