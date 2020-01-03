/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.02%)
 * Total Accepted:    127.7K
 * Total Submissions: 319K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vis;
        for (int i = 0; i < s.length(); i++) {
            if (isvowel(s[i])) {
                vis.push_back(i);
            }
        }

        int i = 0;
        int j = vis.size() - 1;
        while (i < j) {
            swap(s[vis[i]], s[vis[j]]);
            i++;
            j--;
        }
        return s;
    }

private:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
            ;
    }
};

