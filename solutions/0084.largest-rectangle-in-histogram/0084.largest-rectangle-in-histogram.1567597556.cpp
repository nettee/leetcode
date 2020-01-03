class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        int N = heights.size();
        
        // For each bar, we calculate the max rectangle of its height
        
        // left[i] = the index of the left most consecutive bar with height no less than bar[i]
        vector<int> left(N, 0);
        {
            stack<int> s;
            for (int j = 0; j < N; j++) {
                left[j] = j;
                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    left[j] = left[s.top()];
                    s.pop();
                }
                s.push(j);
            }
        }
        
        // right[i] = the index of the right most consecutive bar with height no less than bar[i]
        vector<int> right(N, 0);
        {
            stack<int> s;
            for (int j = N-1; j >= 0; j--) {
                right[j] = j;
                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    right[j] = right[s.top()];
                    s.pop();
                }
                s.push(j);
            }
        }
        
        int maxs = 0;
        for (int i = 0; i < N; i++) {
            int s = heights[i] * (right[i] - left[i] + 1);
            maxs = max(maxs, s);
        }
        
        return maxs;
    }
};
