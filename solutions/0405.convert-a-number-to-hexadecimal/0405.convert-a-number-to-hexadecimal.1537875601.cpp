/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (41.16%)
 * Total Accepted:    38.8K
 * Total Submissions: 94.4K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */
class Solution {
public:
    string toHex(int num) {
        unsigned int value = (unsigned int) num;
        if (value == 0) {
            return "0";
        }
        string res;
        while (value > 0) {
            int q = value % 16;
            char c = toHexChar(q);
            res.insert(res.begin(), c);
            value /= 16;
        }
        return res;
    }
private:
    char toHexChar(int n) {
        if (n < 10) {
            return '0' + n;
        } else {
            return 'a' + (n - 10);
        }
    }
};

