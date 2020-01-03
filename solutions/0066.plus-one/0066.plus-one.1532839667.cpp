/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (39.88%)
 * Total Accepted:    269K
 * Total Submissions: 674.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        plusOne0(digits, digits.size() - 1);
        return digits;
    }

    void plusOne0(vector<int>& digits, int p) {
        if (p == -1) {
            vector<int> nd;
            nd.push_back(1);
            for (int i = 0; i < digits.size(); i++) {
                nd.push_back(digits[i]);
            }
            digits = nd;
            return;
        }
        if (digits[p] + 1 >= 10) {
            digits[p] = 0;
            plusOne0(digits, p - 1);
        } else {
            digits[p]++;
        }
    }
};

