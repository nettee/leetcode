/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (44.31%)
 * Total Accepted:    48.3K
 * Total Submissions: 109K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        while (pos < s.length()) {
            int left = s.length() - pos;
            if (left >= 2 * k) {
                reversek(s, pos, k);
                pos += 2 * k;
            } else if (left >= k) {
                reversek(s, pos, k);
                pos += left;
            } else {
                reversek(s, pos, left);
                pos += left;
            }
        }
        return s;
    }

private:
    // reverse k chars from position pos
    void reversek(string& s, int pos, int k) {
        int i = pos;
        int j = pos + k - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

};

