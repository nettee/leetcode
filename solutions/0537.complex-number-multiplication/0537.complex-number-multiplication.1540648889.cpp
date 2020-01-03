/*
 * [537] Complex Number Multiplication
 *
 * https://leetcode.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (64.29%)
 * Total Accepted:    30.4K
 * Total Submissions: 47.3K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 
 * Given two strings representing two complex numbers.
 * 
 * 
 * You need to return a string representing their multiplication. Note i2 = -1
 * according to the definition.
 * 
 * 
 * Example 1:
 * 
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert
 * it to the form of 0+2i.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert
 * it to the form of 0+-2i.
 * 
 * 
 * 
 * Note:
 * 
 * The input strings will not have extra blank.
 * The input strings will be given in the form of a+bi, where the integer a and
 * b will both belong to the range of [-100, 100]. And the output should be
 * also in this form.
 * 
 * 
 */
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> c1 = parse(a);
        pair<int, int> c2 = parse(b);
        int real = c1.first * c2.first - c1.second * c2.second;
        int img = c1.first * c2.second + c1.second * c2.first;
        string res;
        res += to_string(real);
        res += '+';
        res += to_string(img);
        res += 'i';
        return res;
    }

private:
    pair<int, int> parse(string& a) {
        int k = a.find('+');
        int real = stoi(a.substr(0, k));
        int img = stoi(a.substr(k+1, a.length() - k - 2));
        return make_pair(real, img);
    }
};

