/*
 * [834] Ambiguous Coordinates
 *
 * https://leetcode.com/problems/ambiguous-coordinates/description/
 *
 * algorithms
 * Medium (42.33%)
 * Total Accepted:    4.7K
 * Total Submissions: 11.1K
 * Testcase Example:  '"(123)"'
 *
 * We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then,
 * we removed all commas, decimal points, and spaces, and ended up with the
 * string S.  Return a list of strings representing all possibilities for what
 * our original coordinates could have been.
 * 
 * Our original representation never had extraneous zeroes, so we never started
 * with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other
 * number that can be represented with less digits.  Also, a decimal point
 * within a number never occurs without at least one digit occuring before it,
 * so we never started with numbers like ".1".
 * 
 * The final answer list can be returned in any order.  Also note that all
 * coordinates in the final answer have exactly one space between them
 * (occurring after the comma.)
 * 
 * 
 * Example 1:
 * Input: "(123)"
 * Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
 * 
 * 
 * 
 * Example 2:
 * Input: "(00011)"
 * Output:  ["(0.001, 1)", "(0, 0.011)"]
 * Explanation: 
 * 0.0, 00, 0001 or 00.01 are not allowed.
 * 
 * 
 * 
 * Example 3:
 * Input: "(0123)"
 * Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)",
 * "(0.12, 3)"]
 * 
 * 
 * 
 * Example 4:
 * Input: "(100)"
 * Output: [(10, 0)]
 * Explanation: 
 * 1.0 is not allowed.
 * 
 * 
 * 
 * 
 * Note: 
 * 
 * 
 * 4 <= S.length <= 12.
 * S[0] = "(", S[S.length - 1] = ")", and the other elements in S are
 * digits.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for (int k = 2; k <= S.length() - 2; k++) {
            tryk(res, S, k);
        }
        return res;
    }

private:
    void tryk(vector<string>& res, string& s, int k) {
        string first = s.substr(1, k - 1);
        string second = s.substr(k, s.length() - k - 1);
        vector<string> first_c;
        vector<string> second_c;
        generate(first, first_c);
        generate(second, second_c);
        for (string& fc : first_c) {
            for (string& sc : second_c) {
                string r = "(" + fc + ", " + sc + ")";
                res.push_back(r);
            }
        }
    }

    void generate(string& origin, vector<string>& out) {
        if (origin.length() == 1 && origin == "0") {
            out.push_back(origin);
        } else if (origin[0] == '0' && origin[origin.size()-1] != '0') {
            string r = origin;
            r.insert(r.begin() + 1, '.');
            out.push_back(r);
        } else if (origin[0] != '0' && origin[origin.size()-1] == '0') {
            string r = origin;
            out.push_back(r);
        } else if (origin[0] != '0' && origin[origin.size()-1] != '0') {
            out.push_back(origin);
            for (int i = 1; i < origin.length(); i++) {
                string r = origin;
                r.insert(r.begin() + i, '.');
                out.push_back(r);
            }
        }
    }
};

