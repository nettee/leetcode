class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for (int x : findNums) {
            res.push_back(ng(x, nums));
        }
        return res;
    }
    
    int ng(int x, vector<int>& a) {
        int i = 0;
        while (i < a.size() && a[i] != x) {
            i++;
        }
        if (i < a.size()) {
            for (int j = i + 1; j < a.size(); j++) {
                if (a[j] > x) {
                    return a[j];
                }
            }
            return -1;
        } else {
            return -1;
        }
    }
};
