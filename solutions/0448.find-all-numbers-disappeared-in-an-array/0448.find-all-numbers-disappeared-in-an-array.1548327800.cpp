class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        bool* appear = new bool[N];
        for (int i = 0; i < N; i++) {
            appear[i] = false;
        }
        for (int n : nums) {
            appear[n-1] = true;
        }
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (!appear[i]) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
