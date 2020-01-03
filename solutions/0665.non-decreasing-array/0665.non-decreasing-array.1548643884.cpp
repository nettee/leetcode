class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() <= 2) {
            return true;
        }
        int N = nums.size();
        int decs = 0;
        int deci;
        for (int i = 1; i < N; i++) {
            if (nums[i-1] > nums[i]) {
                decs++;
                if (decs > 1) {
                    return false;
                }
                deci = i;
            }
        }
        if (decs == 0) {
            return true;
        }
        // Decs == 1
        return deci == N - 1
            || nums[deci-1] <= nums[deci+1]
            || deci-1 == 0
            || nums[deci-2] <= nums[deci];
    }
    
    pair<int, int> findDec(vector<int>& a) {
        int N = a.size();
        for (int i = 1; i < N; i++) {
            if (a[i-1] > a[i]) {
                return make_pair(i-1, i);
            }
        }
    }
};
