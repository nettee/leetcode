/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.88%)
 * Total Accepted:    89.4K
 * Total Submissions: 230K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) {
            return false;
        } else if (num == 1) {
            return true;
        }
        int s = 0;
        for (int k = 1; k <= num / 2; k++) {
            s += 2 * k - 1;
            if (s == num) {
                return true;
            } else if (s > num) {
                return false;
            }
        }
        return false;
    }
};

