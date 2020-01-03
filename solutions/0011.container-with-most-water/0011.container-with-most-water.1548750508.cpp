class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int mc = 0;
        int i = 0;
        int j = N-1;
        while (i < j) {
            mc = max(mc, (j-i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return mc;
    }
};
