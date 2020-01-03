class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) {
            return 0;
        }
        // H(0) = H(N-1) = 0
        // H(k) = min{ max{ A[0..k) }, max{ A(k..N) } }
        int N = height.size();
        int* maxleft = new int[N];
        int* maxright = new int[N];
        int ml = height[0];
        for (int i = 1; i < N; i++) {
            maxleft[i] = ml;
            ml = max(ml, height[i]);
        }
        int mr = height[N-1];
        for (int i = N-1; i > 0; i--) {
            maxright[i] = mr;
            mr = max(mr, height[i]);
        }
        int water = 0;
        for (int i = 1; i < N-1; i++) {
            int h = min(maxleft[i], maxright[i]) - height[i];
            if (h > 0) {
                water += h;
            }
        }
        return water;
    }
};
