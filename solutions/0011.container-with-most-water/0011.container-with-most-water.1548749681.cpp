class Solution {
public:
    int maxArea(vector<int>& height) {
        // Naive method
        int N = height.size();
        int mc = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                mc = max(mc, (j-i) * min(height[i], height[j]));
            }
        }
        return mc;
    }
};
