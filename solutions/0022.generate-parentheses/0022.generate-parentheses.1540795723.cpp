/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (50.81%)
 * Total Accepted:    258.5K
 * Total Submissions: 508.8K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, string(), n, n, 0);
        return res;
    }

private:
    void generate(vector<string>& res, string s, int l_left, int r_left, int depth) {
        if (l_left == 0 && r_left == 0) {
            res.push_back(s);
            return;
        }
        if (l_left > 0) {
            generate(res, s + '(', l_left - 1, r_left, depth + 1);
        }
        if (depth > 0 && r_left > 0) {
            generate(res, s + ')', l_left, r_left - 1, depth - 1);
        }
    }
};

