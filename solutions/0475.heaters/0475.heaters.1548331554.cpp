class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int r = mindist(houses[0], heaters);
        for (int h : houses) {
            r = max(r, mindist(h, heaters));
        }
        return r;
    }
    
    int mindist(int house, vector<int>& heaters) {
        int res = abs(heaters[0] - house);
        for (int heater : heaters) {
            res = min(res, abs(heater - house));
        }
        return res;
    }
};
