class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        int N = A.size();
        
        int count = 0;
        
        int i = 0;
        while (i < N) {
            int j = i + 1;
            while (j < N && A[j] - A[j-1] == A[i+1] - A[i]) {
                j++;
            }
            // 等差数列的长度是 j - i
            int k = j - i;
            count += (k - 1) * (k - 2) / 2;
            i = max(i + 1, j - 2);
        }
        
        return count;
    }
};
