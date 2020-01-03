class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        int i = 0;
        int k = 0; // dest
        while (i < N) {
            int j = i;
            while (j < N && chars[j] == chars[i]) {
                j++;
            }
            chars[k++] = chars[i];
            if (j - i > 1) {
                string s = to_string(j - i);
                for (char c : s) {
                    chars[k++] = c;
                }
            }
            i = j;
        }
        return k;
    }
};
