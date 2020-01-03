class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int N = A.size();
        int j = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] % 2 == 0) {
                swap(A[i], A[j]);
                j++;
            }
        }
        return A;
    }
};
