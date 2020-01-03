/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.72%)
 * Total Accepted:    288.9K
 * Total Submissions: 910.7K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return string("");
        }

        int minlen = strs[0].length();
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].length();
            if (len < minlen) {
                minlen = len;
            }
        }

        char prefix[minlen+1];
        memset(prefix, 0, minlen+1);

        for (int j = 0; j < minlen; j++) {
            char base = strs[0][j];
            bool same = true;
            for (int i = 0; i < strs.size(); i++) {
                char c = strs[i][j];
                if (c != base) {
                    same = false;
                    break;
                }
            }
            if (same) {
                prefix[j] = base;
            } else {
                break;
            }
        }

        return string(prefix);
    }
};

