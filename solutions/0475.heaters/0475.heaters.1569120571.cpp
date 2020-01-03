class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // for every house, find its shortest distance to a heater
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int h : houses) {
            radius = max(radius, minDistance(heaters, h));
        }
        return radius;
    }
    
    int minDistance(vector<int>& heaters, int house) {
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        if (it == heaters.end()) {
            // house at the right of all heaters
            return house - heaters[heaters.size()-1];
        } else if (it == heaters.begin()) {
            // house at the left of all heaters
            return heaters[0] - house;
        } else {
            int i = it - heaters.begin();
            return min(heaters[i] - house, house - heaters[i-1]);
        }
    }
};
