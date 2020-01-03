class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int incs = 0;
        int decs = 0;
        for (char c : S) {
            if (c == 'I') {
                incs++;
            } else {
                decs++;
            }
        }
        int mid = decs;
        int i = mid - 1;
        int j = mid + 1;
        vector<int> res;
        res.push_back(mid);
        for (char c : S) {
            if (c == 'I') {
                res.push_back(j++);
            } else {
                res.push_back(i--);
            }
        }
        return res;
    }
};
