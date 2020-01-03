class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> B(A.begin(), A.end());
        for (int i = 0; i < B.size(); i++) {
            B[i] = B[i] * B[i];
        }
        sort(B.begin(), B.end());
        return B;
    }
};
