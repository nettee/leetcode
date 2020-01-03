class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.empty()) {
            return 1;
        }
        
        int N = arr.size();
        // left_max[i] = max value in arr[0..i)
        vector<int> left_max(N, 0);
        // right_min[j] = min value in arr[j..N)
        vector<int> right_min(N, 0);
        
        int curmax = INT_MIN;
        for (int i = 0; i < N; i++) {
            left_max[i] = curmax;
            curmax = max(curmax, arr[i]);
        }
        
        int curmin = arr[N-1];
        for (int j = N-1; j >= 0; j--) {
            curmin = min(curmin, arr[j]);
            right_min[j] = curmin;
        }
        
        int count = 0;
        for (int v = 1; v < N; v++) {
            if (left_max[v] < right_min[v]) {
                count++;
            }
        }
        return count + 1;
    }
};
