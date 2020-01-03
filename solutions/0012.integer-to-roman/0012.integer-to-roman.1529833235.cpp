class Solution {
public:
    string intToRoman(int num) {
        int thds = num / 1000;
        int huns = (num % 1000) / 100;
        int tens = (num % 100) / 10;
        int ones = num % 10;
        string res;
        if (thds > 0) {
            res += string(thd_reps[thds]);
        }
        if (huns > 0) {
            res += string(hun_reps[huns]);
        }
        if (tens > 0) {
            res += string(ten_reps[tens]);
        }
        if (ones > 0) {
            res += string(one_reps[ones]);
        }
        return res;
    }
private:
    char *thd_reps[10] = {"O", "M", "MM", "MMM"};
    char *hun_reps[10] = {"O", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *ten_reps[10] = {"O", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *one_reps[10] = {"O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
};
