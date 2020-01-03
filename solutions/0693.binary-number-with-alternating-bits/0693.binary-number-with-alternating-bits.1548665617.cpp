class Solution {
public:
    bool hasAlternatingBits(int n) {
        if ((n & 0x3) == 0x1) {
            while (n > 0) {
                if ((n & 0x3) != 0x1) {
                    return false;
                }
                n >>= 2;
            }
            return true;
        } else if ((n & 0x3) == 0x2) {
            while (n > 0) {
                if ((n & 0x3) != 0x2) {
                    return false;
                }
                n >>= 2;
            }
            return true;
        } else {
            return false;
        }
    }
};
