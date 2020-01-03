class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            maxa = max(maxa, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxa;
    }
};
