class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.size() < 2) {
            return 0;
        }
        //  [8, 1, 5, 2, 6]
        // +[0, 1, 2, 3, 4] = [8, 2, 7, 5, 10]
        // -[0, 1, 2, 3, 4] = [8, 0, 3, -1, 2]
        //     8  0  3 -1  2
        //  8     8 11  7 10      8 + max{0, 3, -1, 2}
        //  2        5  1  4      2 + max   {3, -1, 2}
        //  7           6  9      7 + max      {-1, 2}
        //  5              7      5 + max          {2}
        // 10
        int N = A.size();
        vector<int> plus(N, 0);
        vector<int> minus(N, 0);
        for (int i = 0; i < N; i++) {
            plus[i] = A[i] + i;
            minus[i] = A[i] - i;
        }
        vector<int> rightmax(N, 0);
        int curmax = INT_MIN;
        for (int i = N-1; i > 0; i--) {
            curmax = max(curmax, minus[i]);
            rightmax[i] = curmax;
        }
        
        int res = INT_MIN;
        for (int i = 1; i < N; i++) {
            res = max(res, plus[i-1] + rightmax[i]);
        }
        return res;
    }
};
