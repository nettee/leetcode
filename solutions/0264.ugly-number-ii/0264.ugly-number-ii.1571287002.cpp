class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(n, 0);
        uglies[0] = 1;
        int j2 = 0;
        int j3 = 0;
        int j5 = 0;
        
        for (int k = 1; k < n; k++) {
            int u2 = 2 * uglies[j2];
            int u3 = 3 * uglies[j3];
            int u5 = 5 * uglies[j5];
            int u = min(min(u2, u3), u5);
            uglies[k] = u;
            while (2 * uglies[j2] <= u) {
                j2++;
            }
            while (3 * uglies[j3] <= u) {
                j3++;
            }
            while (5 * uglies[j5] <= u) {
                j5++;
            }
        }
        
        return uglies[n-1];
    }
};
