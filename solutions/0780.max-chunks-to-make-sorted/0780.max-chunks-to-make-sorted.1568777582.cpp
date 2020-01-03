class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty()) {
            return 1;
        }
        int N = arr.size();
        // leftmax[i] = max of arr[0..i)
        vector<int> leftmax(N, 0);
        // rightmin[i] = min of arr[i..N)
        vector<int> rightmin(N, 0);
        
        int curmax = 0;
        for (int i = 0; i < N; i++) {
            leftmax[i] = curmax;
            curmax = max(curmax, arr[i]);
        }
        
        int curmin = INT_MAX;
        for (int j = N-1; j >= 0; j--) {
            curmin = min(curmin, arr[j]);
            rightmin[j] = curmin;
        }
        
        int count = 0;
        // Split point: arr[0..v) and arr[v..N)
        for (int v = 1; v < N; v++) {
            if (leftmax[v] < rightmin[v]) {
                count++;
            }
        }
        return count + 1;
    }
};
