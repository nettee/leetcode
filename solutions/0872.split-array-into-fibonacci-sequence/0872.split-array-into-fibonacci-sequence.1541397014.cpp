/*
 * [872] Split Array into Fibonacci Sequence
 *
 * https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
 *
 * algorithms
 * Medium (33.77%)
 * Total Accepted:    6K
 * Total Submissions: 17.9K
 * Testcase Example:  '"123456579"'
 *
 * Given a string S of digits, such as S = "123456579", we can split it into a
 * Fibonacci-like sequence [123, 456, 579].
 * 
 * Formally, a Fibonacci-like sequence is a list F of non-negative integers
 * such that:
 * 
 * 
 * 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer
 * type);
 * F.length >= 3;
 * and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 * 
 * 
 * Also, note that when splitting the string into pieces, each piece must not
 * have extra leading zeroes, except if the piece is the number 0 itself.
 * 
 * Return any Fibonacci-like sequence split from S, or return [] if it cannot
 * be done.
 * 
 * Example 1:
 * 
 * 
 * Input: "123456579"
 * Output: [123,456,579]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "11235813"
 * Output: [1,1,2,3,5,8,13]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "112358130"
 * Output: []
 * Explanation: The task is impossible.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "0123"
 * Output: []
 * Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not
 * valid.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "1101111"
 * Output: [110, 1, 111]
 * Explanation: The output [11, 0, 11, 11] would also be accepted.
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= S.length <= 200
 * S contains only digits.
 * 
 * 
 */
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int r1, r2;
        bool res = try1(r1, r2, S);
        if (res) {
            return gen(S, r1, r2);
        } else {
            return vector<int>();
        }
    }

private:
    bool try1(int& r1, int& r2, string& s) {
        int n1 = min(10, static_cast<int>(s.length() / 2));
        for (int k1 = 1; k1 <= n1; k1++) {
            int a1 = stol(s.substr(0, k1));
            if (try2(r1, r2, s, k1, a1)) {
                return true;
            }
        }
        return false;
    }

    bool try2(int& r1, int& r2, string& s, int k1, int a1) {
        int n2 = min(10, static_cast<int>((s.length() - k1) / 2));
        for (int k2 = 1; k2 <= n2; k2++) {
            int a2 = stol(s.substr(k1, k2));
            if (check(s, a1, a2)) {
                r1 = a1;
                r2 = a2;
                return true;
            }
        }
        return false;
    }

    vector<int> gen(string& s, int r1, int r2) {
        vector<int> res{r1, r2};
        string r;
        r += to_string(r1);
        r += to_string(r2);
        while (r.length() < s.length()) {
            int r3 = r1 + r2;
            r += to_string(r3);
            res.push_back(r3);
            r1 = r2;
            r2 = r3;
        }
        return res;
    }

    bool check(string& s, int a1, int a2) {
        string r;
        r += to_string(a1);
        r += to_string(a2);
        while (r.length() < s.length()) {
            int a3 = a1 + a2;
            r += to_string(a3);
            a1 = a2;
            a2 = a3;
        }
        return s == r;
    }
};


