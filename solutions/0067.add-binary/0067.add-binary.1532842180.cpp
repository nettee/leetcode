/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.11%)
 * Total Accepted:    218.2K
 * Total Submissions: 621.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        int n = n1 > n2 ? n1 : n2;
        return addBinary(a, b, n);
    }

    string addBinary(string a, string b, int n) {
        char *cs = new char[n + 2];
        cs[n + 1] = '\0';
        int cc = 0;
        for (int i = 0; i < n; i++) {
            int b1 = getDigit(a, i);
            int b2 = getDigit(b, i);
            int s = b1 + b2 + cc;
            cs[n - i] = '0' + (s & 1);
            cc = (s >> 1) & 1;
        }
        if (cc > 0) {
            cs[0] = '1';
            return string(cs);
        } else {
            return string(cs+1);
        }
    }

    int getDigit(string s, int d) {
        int n = s.length();
        if (d >= n) {
            return 0;
        } else {
            int i = s.length() - 1 - d;
            char c = s[i];
            return c - '0';
        }
    }
};

