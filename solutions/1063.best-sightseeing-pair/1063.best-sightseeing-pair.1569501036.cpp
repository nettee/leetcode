class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
        int curmax = INT_MIN;
        for (int a : A) {
            res = max(res, curmax + a);
            curmax = max(curmax, a) - 1;
        }
        return res;
    }
};
