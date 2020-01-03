class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        bool hasOdd = false;
        int sumEven = 0;
        for (auto e : count) {
            int c = e.second;
            if (c % 2 == 0) {
                sumEven += c;
            } else {
                hasOdd = true;
                sumEven += c - 1;
            }
        }
        return hasOdd ? sumEven + 1 : sumEven;
    }
};
