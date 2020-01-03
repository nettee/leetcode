/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (52.85%)
 * Total Accepted:    215.7K
 * Total Submissions: 408K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int s = 0;
            while (num > 0) {
                s += num % 10;
                num /= 10;
            }
            num = s;
        }
        return num;
    }
};

