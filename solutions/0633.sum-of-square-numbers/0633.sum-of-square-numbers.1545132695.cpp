/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.54%)
 * Total Accepted:    34.9K
 * Total Submissions: 107.3K
 * Testcase Example:  '5'
 *
 * 
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 */
class Solution {
public:
    // Assume a > b
    // Therefore sqrt(c/2) < a < sqrt(c)
    bool judgeSquareSum(int c) {
        for (int a = (int) sqrt(c/2); a <= (int) sqrt(c); a++) {
            int bq = c - a * a;
            int b = (int) sqrt(bq);
            if (b * b == bq) {
                return true;
            }
        }
        return false;
    }
};

