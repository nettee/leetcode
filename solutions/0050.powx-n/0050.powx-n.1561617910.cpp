/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (n > 0) {
            return mPow(x, n);
        } else if (n == -2147483648) {
            return (1/x) * mPow(1/x, 2147483647);
        } else {
            return mPow(1/x, -n);
        }
    }

    double mPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double y = mPow(x, n / 2);
        if (n % 2 == 1) {
            return y * y * x;
        } else {
            return y * y;
        }
    }
};


