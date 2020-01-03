/*
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.08%)
 * Total Accepted:    198.3K
 * Total Submissions: 618.1K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int N = s.length();
        int i = N - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        if (i < 0) {
            return 0;
        }
        int end = i;
        while (i >= 0 && s[i] != ' ') {
            i--;
        }
        return end - i;
    }
};

