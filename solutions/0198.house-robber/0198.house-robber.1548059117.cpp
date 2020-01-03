class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } 
        if (nums.size() == 1) {
            return nums[0];
        }
        // subproblems:
        // RobA(a, k): rob a[0..k] with a[k]
        // RobB(a, k): rob b[0..k] without a[k]
        //
        // Rob(a) = max{robA(a, N-1), robb(a, N-1)}
        //
        // RobA(a, 0) = a[0]
        // RobA(a, 1) = a[1]
        // RobA(a, k) = a[k] + max{robA(a, k-2), robB(a, k-1)}
        // RobB(a, 0) = 0
        // RobB(a, k) = max{robA(a, k-1), robB(a, k-1)}
        
        int N = nums.size();
        int* A = new int[N];
        int* B = new int[N];
        A[0] = nums[0];
        A[1] = nums[1];
        B[0] = 0;
        B[1] = max(A[0], B[0]);
        for (int k = 2; k < N; k++) {
            A[k] = nums[k] + max(A[k-2], B[k-1]);
            B[k] = max(A[k-1], B[k-1]);
        }
        return max(A[N-1], B[N-1]);
    }
};
