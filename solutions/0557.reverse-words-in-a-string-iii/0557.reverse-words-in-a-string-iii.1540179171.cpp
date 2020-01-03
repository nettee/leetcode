/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (61.76%)
 * Total Accepted:    94.2K
 * Total Submissions: 152.5K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s[j] != ' ') {
                j++;
            }
            reversew(s, i, j);
            i = j + 1;
        }
        return s;
    }

private:
    // reverse word
    void reversew(string& s, int start, int end) {
        int i = start;
        int j = end - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

