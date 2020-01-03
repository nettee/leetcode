class Solution {
public:
    string reverseOnlyLetters(string S) {
        string r(S);
        int N = S.length();
        int i = 0;
        int j = N - 1;
        while (i < j) {
            while (i < j && !isalpha(r[i])) {
                i++;
            }
            while (j > i && !isalpha(r[j])) {
                j--;
            }
            if (i >= j) {
                break;
            }
            swap(r[i], r[j]);
            i++;
            j--;
        }
        return r;
    }
};
