class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else if (n == 3) {
            return 3;
        }
        vector<int> uglies(n+1, 0);
        uglies[1] = 1;
        uglies[2] = 2;
        uglies[3] = 3;
        int t2 = 2;
        int t3 = 2;
        int t5 = 1;
        for (int k = 4; k <= n; k++) {
            // generate the k-th ugly number
            int u2 = uglies[t2] * 2;
            int u3 = uglies[t3] * 3;
            int u5 = uglies[t5] * 5;
            int u = min(min(u2, u3), u5);
            uglies[k] = u;
            while (uglies[t2] * 2 <= uglies[k]) {
                t2++;
            }
            while (uglies[t3] * 3 <= uglies[k]) {
                t3++;
            }
            while (uglies[t5] * 5 <= uglies[k]) {
                t5++;
            }
        }
        return uglies[n];
    }
};
