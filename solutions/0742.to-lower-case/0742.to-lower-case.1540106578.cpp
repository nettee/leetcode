/*
 * [742] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (74.25%)
 * Total Accepted:    37.9K
 * Total Submissions: 51.1K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "Hello"
 * Output: "hello"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "here"
 * Output: "here"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string toLowerCase(string str) {
        string s(str);
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if ('A' <= c && c <= 'Z') {
                s[i] = c - 'A' + 'a';
            }
        }
        return s;
    }
};

