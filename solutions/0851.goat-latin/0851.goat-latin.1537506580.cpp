/*
 * [851] Goat Latin
 *
 * https://leetcode.com/problems/goat-latin/description/
 *
 * algorithms
 * Easy (54.78%)
 * Total Accepted:    16.2K
 * Total Submissions: 29.6K
 * Testcase Example:  '"I speak Goat Latin"'
 *
 * A sentence S is given, composed of words separated by spaces. Each word
 * consists of lowercase and uppercase letters only.
 * 
 * We would like to convert the sentence to "Goat Latin" (a made-up language
 * similar to Pig Latin.)
 * 
 * The rules of Goat Latin are as follows:
 * 
 * 
 * If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of
 * the word.
 * For example, the word 'apple' becomes 'applema'.
 * 
 * If a word begins with a consonant (i.e. not a vowel), remove the first
 * letter and append it to the end, then add "ma".
 * For example, the word "goat" becomes "oatgma".
 * 
 * Add one letter 'a' to the end of each word per its word index in the
 * sentence, starting with 1.
 * For example, the first word gets "a" added to the end, the second word gets
 * "aa" added to the end and so on.
 * 
 * 
 * Return the final sentence representing the conversion from S to Goat
 * Latin. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "I speak Goat Latin"
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "The quick brown fox jumped over the lazy dog"
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
 * hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * S contains only uppercase, lowercase and spaces. Exactly one space between
 * each word.
 * 1 <= S.length <= 150.
 * 
 */
class Solution {
public:
    string toGoatLatin(string S) {
        string sp(" ");
        vector<string> v = split(S, sp);
        string res;
        for (int i = 0; i < v.size(); i++) {
            res += trans(v[i], i+1);
            if (i < v.size() - 1) {
                res += sp;
            }
        }
        return res;
    }

private:
    vector<string> split(string S, string sp) {
        vector<string> res;
        int i = 0;
        int j = S.find(sp);
        while (j != string::npos) {
            string w = S.substr(i, j-i);
            res.push_back(w);
            i = j + sp.size();
            j = S.find(sp, i);
        }
        if (i < S.length()) {
            string w = S.substr(i);
            res.push_back(w);
        }
        return res;
    }

    string trans(string a, int r) {
        string b;
        char c = a[0];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            b = a + string("ma");
        } else {
            b = a.substr(1, a.length()-1) + a[0] + string("ma");
        }
        string rep(r, 'a');
        return b + rep;
    }
};

