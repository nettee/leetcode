class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int N = A.size();
        if (N <= 1) {
            return 0;
        }
        
        // rmax[j] = max A[j..)
        vector<int> rmax(N, 0);
        
        int curmax = INT_MIN;
        for (int j = N-1; j >= 0; j--) {
            curmax = max(curmax, A[j]);
            rmax[j] = curmax;
        }
        
        int i = 0;
        int j = 0;
        int maxwidth = 0;
        while (j < N) {
            if (i < j && A[i] > rmax[j]) {
                i++;
            } else {
                maxwidth = max(maxwidth, j - i);
                j++;
            }
        }
        return maxwidth;
    }
};
