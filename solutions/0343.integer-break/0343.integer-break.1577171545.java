class Solution {
    public int integerBreak(int n) {
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        }
        int product = 1;
        while (n > 1) {
            if (n == 2 || n == 4) {
                product *= 2;
                n -= 2;
            } else {
                product *= 3;
                n -= 3;
            }
        }
        return product;
    }
}
