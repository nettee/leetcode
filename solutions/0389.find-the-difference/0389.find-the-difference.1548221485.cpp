class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26];
        for (int i = 0; i < 26; i++) {
            count[i] = 0;
        }
        for (char c : s) {
            count[c-'a']++;
        }
        for (char c : t) {
            count[c-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == -1) {
                return 'a' + i;
            }
        }
        return 'A';
    }
};
