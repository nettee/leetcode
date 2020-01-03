/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.42%)
 * Total Accepted:    46.1K
 * Total Submissions: 126.6K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) {
        int sc = 0; // segment count
        int i = 0;
        while (i < s.length() && isspace(s[i])) {
            i++;
        }
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && !isspace(s[j])) {
                j++;
            }
            int k = j;
            while (k < s.length() && isspace(s[k])) {
                k++;
            }
            i = k;
            sc++;
        }
        return sc;
    }
};

