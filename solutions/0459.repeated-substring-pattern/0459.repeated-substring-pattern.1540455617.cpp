/*
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.73%)
 * Total Accepted:    65.5K
 * Total Submissions: 169.3K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aba"
 * Output: False
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() <= 1) {
            return false;
        }
        char f = s[0];
        for (int i = 1; i <= s.length() / 2; i++) {
            if (s[i] == f) {
                bool can = check(s, i);
                if (can) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool check(string& s, int i) {
        if (s.length() % i != 0) {
            return false;
        }
        string p = s.substr(0, i);
        for (int k = i; k < s.length(); k += i) {
            string q = s.substr(k, i);
            if (q != p) {
                return false;
            }
        }
        return true;
    }
};

