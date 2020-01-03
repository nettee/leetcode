/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (61.61%)
 * Total Accepted:    309.8K
 * Total Submissions: 502.8K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: "hello"
 * Output: "olleh"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

