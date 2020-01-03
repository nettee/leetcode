/*
 * [837] Most Common Word
 *
 * https://leetcode.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (41.86%)
 * Total Accepted:    25.1K
 * Total Submissions: 59.8K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * Given a paragraph and a list of banned words, return the most frequent word
 * that is not in the list of banned words.  It is guaranteed there is at least
 * one word that isn't banned, and that the answer is unique.
 * 
 * Words in the list of banned words are given in lowercase, and free of
 * punctuation.  Words in the paragraph are not case sensitive.  The answer is
 * in lowercase.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent
 * non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is
 * banned.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= paragraph.length <= 1000.
 * 1 <= banned.length <= 100.
 * 1 <= banned[i].length <= 10.
 * The answer is unique, and written in lowercase (even if its occurrences in
 * paragraph may have uppercase symbols, and even if it is a proper noun.)
 * paragraph only consists of letters, spaces, or the punctuation symbols
 * !?',;.
 * There are no hyphens or hyphenated words.
 * Words only consist of letters, never apostrophes or other punctuation
 * symbols.
 * 
 * 
 */
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        to_lower(paragraph);
        unordered_map<string,int> freq;
        int i = 0;
        while (i < paragraph.length()) {
            int j = i;
            while (j < paragraph.length() && isalpha(paragraph[j])) {
                j++;
            }
            // word [i..j)
            string word = paragraph.substr(i, j - i);
            freq[word]++;

            int k = j;
            while (k < paragraph.length() && !isalpha(paragraph[k])) {
                k++;
            }
            i = k;
        }

        for (string b : banned) {
            freq[b] = 0;
        }

        int maxf = 0;
        string maxw;
        for (auto e : freq) {
            const string& word = e.first;
            int f = e.second;
            if (f > maxf) {
                maxw = word;
                maxf = f;
            }
        }
        return maxw;
    }

private:
    void to_lower(string& s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
    }
};

