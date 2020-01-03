/*
 * [889] Buddy Strings
 *
 * https://leetcode.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (26.48%)
 * Total Accepted:    12.8K
 * Total Submissions: 48.4K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * Given two strings A and B of lowercase letters, return true if and only if
 * we can swap two letters in A so that the result equals B.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: A = "ab", B = "ba"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = "ab", B = "ab"
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = "aa", B = "aa"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = "aaaaaaabc", B = "aaaaaaacb"
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = "", B = "aa"
 * Output: false
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A and B consist only of lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        vector<int> diffi;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] != B[i]) {
                diffi.push_back(i);
            }
        }
        if (diffi.size() == 0) {
            vector<int> count(26, 0);
            for (char c : A) {
                count[c - 'a']++;
            }
            int maxi = 0;
            for (int t : count) {
                if (t > maxi) {
                    maxi = t;
                }
            }
            return maxi >= 2;
        } else if (diffi.size() == 2) {
            int i1 = diffi[0];
            int i2 = diffi[1];
            return A[i1] == B[i2] && A[i2] == B[i1];
        } else {
            return false;
        }
    }
};

