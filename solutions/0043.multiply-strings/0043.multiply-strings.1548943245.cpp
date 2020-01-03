class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res;
        for (int i = 0; i < num1.length(); i++) {
            char a = num1[i];
            string m = multi(a, num2);
            addTo(res, m, i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    // s in reverse order, e.g. "88065" for 56088
    // return string in reverse order
    string multi(char a, string s) {
        string res;
        int carry = 0;
        for (char b : s) {
            int d = (a - '0') * (b - '0') + carry;
            res += '0' + (d % 10);
            carry = d / 10;
        }
        if (carry > 0) {
            res += '0' + carry; 
        }
        return res;
    }
    
    void addTo(string& dest, string s, int shift) {
        int carry = 0;
        for (int i = 0; i < s.length(); i++) {
            int j = shift + i;
            if (j < dest.length()) {
                int d = (s[i] - '0') + (dest[j] - '0') + carry;
                dest[j] = '0' + (d % 10);
                carry = d / 10;
            } else {
                int d = (s[i] - '0') + carry;
                dest += '0' + (d % 10);
                carry = d / 10;
            }
        }
        if (carry > 0) {
            dest += '0' + carry;
        }
    }
};
