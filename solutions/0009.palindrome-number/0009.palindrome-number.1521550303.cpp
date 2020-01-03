class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        vector<int> digits;
        while (x > 0) {
            int d = x % 10;
            digits.push_back(d);
            x = x / 10;
        }
        for (int i = 0, j = digits.size() - 1; i < j; i++, j--) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }
        return true;
    }
};
