class Solution {
public:
    int reverse(int x) {
        list<int> digits;
        while (x != 0) {
            int d = x % 10;
            digits.push_back(d);
            x = x / 10;
        }
        int res = 0;
        while (digits.size() > 0) {
            int res0 = res;
            int d = digits.front();
            res = res * 10 + d;
            if ((res - d) / 10 != res0) {
                return 0;
            }
            digits.pop_front();
        }
        return res;
    }
};
