class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1;
        int maj2;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int n : nums) {
            if (cnt1 == 0 && cnt2 == 0) {
                maj1 = n;
                cnt1++;
            } else if (cnt1 == 0) {
                if (n == maj2) {
                    cnt2++;
                } else {
                    maj1 = n;
                    cnt1++;
                }
            } else if (cnt2 == 0) {
                if (n == maj1) {
                    cnt1++;
                } else {
                    maj2 = n;
                    cnt2++;
                }
            } else {
                if (n == maj1) {
                    cnt1++;
                } else if (n == maj2) {
                    cnt2++;
                } else {
                    cnt1--;
                    cnt2--;
                }
            }
        }
        vector<int> res;
        if (isMaj(nums, maj1)) {
            res.push_back(maj1);
        }
        if (maj2 != maj1 && isMaj(nums, maj2)) {
            res.push_back(maj2);
        }
        return res;
    }
    
    bool isMaj(vector<int>& a, int k) {
        int count = 0;
        for (int n : a) {
            if (n == k) {
                count++;
            }
        }
        return count > a.size() / 3;
    }
};
