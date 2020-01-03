class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int k = 0;
        int N = chars.size();
        while (i < N) {
            int j = i;
            while (j < N && chars[j] == chars[i]) {
                j++;
            }
            if (j >= i + 2) {
                // more than two chars
                chars[k++] = chars[i];
                for (char c : to_string(j - i)) {
                    chars[k++] = c;
                }
            } else {
                chars[k++] = chars[i];
            }
            i = j;
        }
        return k;
    }
};
