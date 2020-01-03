class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set s1(nums1.begin(), nums1.end());
        unordered_set s2(nums2.begin(), nums2.end());
        vector<int> res;
        for (int n : s1) {
            if (s2.find(n) != s2.end()) {
                res.push_back(n);
            }
        }
        return res;
    }
};
