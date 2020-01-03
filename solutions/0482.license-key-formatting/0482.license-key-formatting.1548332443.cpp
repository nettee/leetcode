class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        reverse(S.begin(), S.end());
        for (char c : S) {
            if (c == '-') {
                continue;
            }
            if ('a' <= c && c <= 'z') {
                c = 'A' + (c - 'a');
            }
            res += c;
            if (res.length() % (K+1) == K) {
                res += '-';
            }
        }
        if (res[res.length()-1] == '-') {
            res.erase(res.end() - 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
