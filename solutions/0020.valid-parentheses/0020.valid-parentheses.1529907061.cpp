/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (34.23%)
 * Total Accepted:    353.1K
 * Total Submissions: 1M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (empty()) {
                    return false;
                }
                char t = top();
                if (!match(t, c)) {
                    return false;
                }
                pop();
            }
        }
        return empty();
    }
private:
    char stack[10000];
    int p = 0;

    void push(char c) {
        stack[p++] = c;
    }

    void pop() {
        p--;
    }

    char top() {
        return stack[p-1];
    }

    bool empty() {
        return p == 0;
    }

    bool match(char o, char c) {
        return (o == '(' && c == ')')
            || (o == '[' && c == ']')
            || (o == '{' && c == '}');
    }
};

