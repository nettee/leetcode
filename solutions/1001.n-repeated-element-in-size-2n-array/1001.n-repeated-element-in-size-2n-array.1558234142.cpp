class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (i >= 1 && A[i] == A[i-1]) {
                return A[i];
            }
            if (i >= 2 && A[i] == A[i-2]) {
                return A[i];
            }
        }
        // Must be a four-element array [x, y, z, x]
        return A[0];
    }
};
