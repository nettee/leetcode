class Solution {
public:
    int findComplement(int num) {
        int d = 0;
        int n = num;
        while (n > 0) {
            d++;
            n >>= 1;
        }
        int mask = (1 << d) - 1;
        return (~num) & mask;
    }
};
