/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (42.26%)
 * Total Accepted:    73.4K
 * Total Submissions: 173.7K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        string res;
        int c = 0;
        while (i >= 0 || j >= 0) {
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int s = n1 + n2 + c;
            res += '0' + (s % 10);
            c = s / 10;
            i--;
            j--;
        }
        if (c > 0) {
            res += '0' + c;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

