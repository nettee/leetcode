/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (37.19%)
 * Total Accepted:    201K
 * Total Submissions: 540.5K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string ns = string("1");
        for (int i = 1; i < n; i++) {
            ns = say(ns);
        }
        return ns;
    }
private:
    string say(string seq) {
        stringstream out;
        int N = seq.length();
        int i = 0;
        while (i < N) {
            char base = seq[i];
            int j = i;
            while (j < N && seq[j] == base) {
                j++;
            }
            int count = j - i;
            out << count << base;
            i = j;
        }
        return out.str();
    }
};

