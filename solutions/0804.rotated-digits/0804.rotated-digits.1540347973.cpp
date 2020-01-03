/*
 * [804] Rotated Digits
 *
 * https://leetcode.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (50.98%)
 * Total Accepted:    16.8K
 * Total Submissions: 32.9K
 * Testcase Example:  '10'
 *
 * X is a good number if after rotating each digit individually by 180 degrees,
 * we get a valid number that is different from X.  Each digit must be rotated
 * - we cannot choose to leave it alone.
 * 
 * A number is valid if each digit remains a digit after rotation. 0, 1, and 8
 * rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
 * other, and the rest of the numbers do not rotate to any other number and
 * become invalid.
 * 
 * Now given a positive number N, how many numbers X from 1 to N are good?
 * 
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: 
 * There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
 * Note that 1 and 10 are not good numbers, since they remain unchanged after
 * rotating.
 * 
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 10000].
 * 
 * 
 */
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            vector<int> digits = toDigits(i);
            if (isGood(digits)) {
                count++;
            }
        }
        return count;
    }

private:
    vector<int> toDigits(int N) {
        vector<int> res;
        while (N > 0) {
            res.push_back(N % 10);
            N /= 10;
        }
        return res;
    }

    bool isGood(vector<int>& digits) {
        bool valid = true;
        bool different = false;
        for (int d : digits) {
            if (!(d == 0 || d == 1 || d == 8 || d == 2 || d == 5 || d == 6 || d == 9)) {
                valid = false;
            }
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                different = true;
            }
        }
        return valid && different;
    }
};

