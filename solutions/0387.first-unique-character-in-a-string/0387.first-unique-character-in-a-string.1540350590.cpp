/*
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (47.71%)
 * Total Accepted:    177.6K
 * Total Submissions: 372.2K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> oc(26, 0); // occur count
        vector<int> fi(26, -1); // first occur index
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (oc[c - 'a'] == 0) {
                fi[c - 'a'] = i;
            }
            oc[c - 'a']++;
        }
        for (char c : s) {
            if (oc[c - 'a'] == 1) {
                return fi[c - 'a'];
            }
        }
        return -1;
    }
};

