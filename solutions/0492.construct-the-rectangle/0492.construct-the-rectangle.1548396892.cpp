class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = (int) sqrt(area);
        for (int w = s; w > 0; w--) {
            int l = area / w;
            if (w * l == area) {
                return vector<int>{l, w};
            }
        }
        return vector<int>();
    }
};
