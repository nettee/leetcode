class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int N = nums.size();
        if (N % k != 0) {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> counter;
        for (int n : nums) {
            counter[n]++;
        }
        
        for (int n : nums) {
            if (counter[n] <= 0) {
                continue;
            }
            for (int i = 0; i < k; i++) {
                if (counter[n+i] <= 0) {
                    return false;
                }
                counter[n+i]--;
            }
        }
        return true;
    }
};
