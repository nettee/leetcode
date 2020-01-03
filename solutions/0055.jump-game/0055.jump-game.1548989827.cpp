class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Subproblem: 
        // canJump(a, i): Can I jump to a[N-1] from a[i]?
        // canJump(a) = canJump(a, 0)
        // 
        // canJump(a, N-1) = true
        // canJump(a, i) = if any j, 1 <= j <= a[i], i+j<N && a[i+j] = true
        
        int N = nums.size();
        bool* can = new bool[N];
        for (int i = 0; i < N; i++) {
            can[i] = false;
        }
        can[N-1] = true;
        for (int k = N-2; k >= 0; k--) {
            // Calculate can[k]
            // We can jump at most nums[k] steps
            for (int j = 1; j <= nums[k]; j++) {
                if (k+j<N && can[k+j]) {
                    can[k] = true;
                    break;
                }
            }
        }
        return can[0];
    }
};
