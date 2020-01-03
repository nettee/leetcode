class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        
        int maxc = 0;
        for (auto e : counter) {
            maxc = max(maxc, e.second);
        }
        
        vector<int> modes;
        for (auto e : counter) {
            if (e.second == maxc) {
                modes.push_back(e.first);
            }
        }
        
        int shortest = nums.size();
        for (int mode : modes) {
            shortest = min(shortest, modeSubLen(nums, mode));
        }
        return shortest;
    }
    
    int modeSubLen(vector<int>& a, int mode) {
        int i = 0;
        while (i < a.size() && a[i] != mode) {
            i++;
        }
        int j = a.size() - 1;
        while (j >= 0 && a[j] != mode) {
            j--;
        }
        return j - i + 1;
    }
};
