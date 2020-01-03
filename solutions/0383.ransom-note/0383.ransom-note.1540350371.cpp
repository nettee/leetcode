/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (48.47%)
 * Total Accepted:    93.3K
 * Total Submissions: 192.4K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rc(26, 0);
        for (char c : ransomNote) {
            rc[c - 'a']++;
        }
        vector<int> mc(26, 0);
        for (char c : magazine) {
            mc[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (rc[i] > mc[i]) {
                return false;
            }
        }
        return true;
    }
};

