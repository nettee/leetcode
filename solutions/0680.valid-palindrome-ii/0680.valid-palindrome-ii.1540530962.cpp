/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.73%)
 * Total Accepted:    47.9K
 * Total Submissions: 146.3K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.length() - 1, 1);
    }

private:
    bool isPalindrome(string& s, int first, int last, int trial) {
        if (first >= last) {
            return true;
        }
        if (s[first] == s[last]) {
            return isPalindrome(s, first + 1, last - 1, trial);
        } else {
            return trial && 
                    (isPalindrome(s, first + 1, last, trial - 1)
                    || isPalindrome(s, first, last - 1, trial - 1));
        }
    }
};

