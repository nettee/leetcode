/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (38.69%)
 * Total Accepted:    298.1K
 * Total Submissions: 770.4K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<int> ds;
        for (char c : digits) {
            ds.push_back(c - '0');
        }
        vector<string> res;
        gen(res, ds, "", 0);
        return res;
    }

private:
    void gen(vector<string>& res, vector<int>& ds, string current, int index) {
        if (index >= ds.size()) {
            res.push_back(current);
            return;
        }
        string can = a[ds[index]];
        for (char c : can) {
            gen(res, ds, current + c, index + 1);
        }
    }

    const string a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};
};

