class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        int i = lower_bound(A.begin(), A.end(), 0) - A.begin();
        int j = i - 1;
        vector<int> res;
        
        while (i < N || j >= 0) {
            int val;
            if (i >= N) {
                val = A[j--];
            } else if (j < 0) {
                val = A[i++];
            } else if (abs(A[i]) < abs(A[j])) {
                val = A[i++];
            } else {
                val = A[j--];
            }
            res.push_back(val * val);
        }
        
        return res;
    }
};
