/*
 * [952] Word Subsets
 *
 * https://leetcode.com/problems/word-subsets/description/
 *
 * algorithms
 * Medium (42.93%)
 * Total Accepted:    5K
 * Total Submissions: 11.5K
 * Testcase Example:  '["amazon","apple","facebook","google","leetcode"]\n["e","o"]'
 *
 * We are given two arrays A and B of words.  Each word is a string of
 * lowercase letters.
 * 
 * Now, say that word b is a subset of word a if every letter in b occurs in a,
 * including multiplicity.  For example, "wrr" is a subset of "warrior", but is
 * not a subset of "world".
 * 
 * Now say a word a from A is universal if for every b in B, b is a subset of
 * a. 
 * 
 * Return a list of all universal words in A.  You can return the words in any
 * order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * Output: ["facebook","google","leetcode"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * Output: ["apple","google","leetcode"]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * Output: ["facebook","google"]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["lo","eo"]
 * Output: ["google","leetcode"]
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["ec","oc","ceo"]
 * Output: ["facebook","leetcode"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length, B.length <= 10000
 * 1 <= A[i].length, B[i].length <= 10
 * A[i] and B[i] consist only of lowercase letters.
 * All words in A[i] are unique: there isn't i != j with A[i] == A[j].
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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> multiCount(26, 0);
        calcMultiCount(B, multiCount);

        vector<string> res;
        for (string& a : A) {
            if (isUniversal(a, multiCount)) {
                res.push_back(a);
            }
        }
        return res;
    }

private:
    void calcMultiCount(vector<string>& B, vector<int>& out) {
        for (string& b : B) {
            vector<int> count(26, 0);
            for (char c : b) {
                count[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                out[i] = max(out[i], count[i]);
            }
        }
    }

    bool isUniversal(string& a, vector<int>& multiCount) {
        vector<int> count(26, 0);
        for (char c : a) {
            count[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] < multiCount[i]) {
                return false;
            }
        }
        return true;
    }

};

